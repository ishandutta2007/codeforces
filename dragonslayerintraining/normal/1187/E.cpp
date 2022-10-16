#include <cstdio>
#include <vector>
#include <stdint.h>

std::vector<int> edges[200005];

int size[200005];
int64_t sum[200005];
int N;

int64_t ans=0;

void dfs1(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs1(child,node);
    size[node]+=size[child];
  }
  sum[node]=size[node];
  for(int child:edges[node]){
    if(child==parent) continue;
    sum[node]+=sum[child];
  }
}

void dfs2(int node,int parent,int64_t up){
  ans=std::max(ans,sum[node]+up);
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs2(child,node,up+sum[node]-sum[child]-size[child]+N-size[child]);
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
  dfs1(0,0);
  dfs2(0,0,0);
  printf("%I64d\n",ans);
  return 0;
}