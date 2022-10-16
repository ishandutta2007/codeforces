#include <iostream>
#include <vector>

int N;

std::vector<int> edges[100000];

int level[100000];

int size[100000];

void dfs_size(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if(child!=parent&&level[child]==0){
      dfs_size(child,node);
      size[node]+=size[child];
    }
  }
}

void dfs(int node,int lvl){
  dfs_size(node,node);
  int subtree=size[node];
  int parent=node;
  while(true){
    int heavy=-1;
    for(int child:edges[node]){
      if(level[child]==0&&child!=parent&&
	 size[child]*2>subtree){
	heavy=child;
	break;
      }
    }
    if(heavy==-1){
      break;
    }else{
      parent=node;
      node=heavy;
    }
  }
  level[node]=lvl;
  for(int child:edges[node]){
    if(level[child]==0){
      dfs(child,lvl+1);
    }
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(0,1);
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%c",'A'+level[i]-1);
  }
  printf("\n");
  return 0;
}