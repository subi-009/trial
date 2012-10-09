 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>


long count=1;

// random function to generate the required no of input elements

void enter_element(unsigned long n,unsigned long list[]) {
 unsigned long ncount;
 srand(time(0));
 for(ncount=0;ncount<=n-1;ncount++) {
  list[ncount]=rand();
  printf("\t %lu", list[ncount]);
 }
 printf("\n done1");
} 

typedef struct node{
  unsigned long data;
  struct node *left;
  struct node *right;
 }tree;
 
 tree* getnode(){
  int size;
  tree *newnode;
  newnode=(tree*)malloc(size);
  count++;
  return newnode;
 }

void readnode(tree *newnode,unsigned long data){
 newnode->data=data;
 newnode->left=NULL;
 newnode->right=NULL;
}

tree* insertnode(tree *btree, tree *temp){
 if(btree==NULL){
  return temp;
 }
 else {
  if(count%2==0)
        btree->left= insertnode(btree->left,temp);
  else
        btree->right=insertnode(btree->right,temp);
 }
 return btree;
}


tree* createbtree(long list[], long ncount){
 tree *btree,*temp;
 long i;
 for(i=0;i<ncount;i++){
  temp=getnode();
  readnode(temp,list[i]);
  btree=insertnode(btree,temp);
  fflush(stdin);
 }
 return btree;
}

void inorder(tree *btree){
 inorder(btree->left);
 printf("%ld",btree->data);
 inorder(btree->right);
}

void main(){
 unsigned long* list;
 unsigned long ncount;
 tree *btree;
 printf("\n Enter the size of the input, no of elements to be inserted into the tree :");
 scanf("%lu",&ncount);
 list= (unsigned long*)malloc(ncount*sizeof(unsigned long));
 printf("\n done2");
 enter_element(ncount,list);
 printf("\n done3");
 btree= createbtree(list,ncount);
 inorder(btree);
}
























