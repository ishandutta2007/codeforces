#include <cstdio>
#include <stdint.h>
#include <vector>

std::vector<int64_t> edges[300000];

int64_t parent[300000];

void dfs0(int64_t node){
  for(int64_t child:edges[node]){
    if(child==parent[node]) continue;
    parent[child]=node;
    dfs0(child);
  }
}

int64_t dfs1(int64_t node){
  int64_t size=1;
  for(int64_t child:edges[node]){
    if(child==parent[node]) continue;
    size+=dfs1(child);
  }
  return size;
}

int main(){
  int64_t N,X,Y;
  scanf("%I64d %I64d %I64d",&N,&X,&Y);
  X--,Y--;
  for(int64_t i=0;i<N-1;i++){
    int64_t A,B;
    scanf("%I64d %I64d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  std::fill(parent,parent+N,-1);
  dfs0(X);
  int64_t sizeY=dfs1(Y);
  std::fill(parent,parent+N,-1);
  dfs0(Y);
  int64_t sizeX=dfs1(X);
  printf("%I64d\n",N*(N-1)-sizeX*sizeY);
  return 0;
}