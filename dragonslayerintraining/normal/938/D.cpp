#include <cstdio>
#include <queue>
#include <vector>
#include <stdint.h>

std::vector<std::pair<int64_t,int64_t> > edges[200000];

int64_t dist[200000];

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=0;i<M;i++){
    int64_t V,U,W;
    scanf("%I64d %I64d %I64d",&V,&U,&W);
    V--,U--;
    edges[U].emplace_back(V,2*W);
    edges[V].emplace_back(U,2*W);
  }
  std::priority_queue<std::pair<int64_t,int64_t> > frontier;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    frontier.emplace(-A,i);
  }
  std::fill(dist,dist+N,1e18);
  while(!frontier.empty()){
    int64_t node=frontier.top().second;
    int64_t dst=-frontier.top().first;
    frontier.pop();
    if(dst>=dist[node]){
      continue;
    }
    dist[node]=dst;
    for(auto e:edges[node]){
      frontier.emplace(-(dst+e.second),e.first);
    }
  }
  for(int i=0;i<N;i++){
    printf("%I64d\n",dist[i]);
  }
  return 0;
}