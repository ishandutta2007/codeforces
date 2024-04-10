#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>

int64_t N;
int64_t as[300005];
int64_t sum[300005];
std::vector<int64_t> edges[300005];

int64_t max,cnt;

void dfs1(int64_t node,int64_t parent){
  sum[node]=as[node];
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    dfs1(child,node);
    if(sum[child]>0) sum[node]+=sum[child];
  }
}

void dfs2(int64_t node,int64_t parent){
  sum[node]=as[node];
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    dfs2(child,node);
    if(sum[child]>0) sum[node]+=sum[child];
  }
  if(sum[node]==max){
    sum[node]=0;
    cnt++;
  }
}

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs1(0,-1);
  max=*std::max_element(sum,sum+N);
  dfs2(0,-1);
  printf("%I64d %I64d\n",max*cnt,cnt);
  return 0;
}