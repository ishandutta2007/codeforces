#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>
#include <queue>

int64_t N,M,K,S;

std::vector<int64_t> goods[100];

std::vector<int64_t> edges[100005];

int64_t dist[100005];
std::vector<int64_t> total[100005];

int main(){
  scanf("%I64d %I64d %I64d %I64d",&N,&M,&K,&S);
  for(int64_t i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    A--;
    goods[A].push_back(i);
  }
  for(int64_t i=0;i<M;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  for(int64_t k=0;k<K;k++){
    std::fill(dist,dist+N,1e9);
    std::queue<int64_t> frontier;
    for(int64_t i:goods[k]){
      dist[i]=0;
      frontier.push(i);
    }
    while(!frontier.empty()){
      int64_t node=frontier.front();
      frontier.pop();
      for(int64_t other:edges[node]){
	if(dist[other]==1e9){
	  frontier.push(other);
	  dist[other]=dist[node]+1;
	}
      }
    }
    /*
    for(int64_t i=0;i<N;i++){
      if(i) printf(" ");
      printf("%I64d",dist[i]);
    }
    printf("\n");
    */
    for(int64_t i=0;i<N;i++){
      total[i].push_back(dist[i]);
    }
  }
  for(int64_t i=0;i<N;i++){
    std::sort(total[i].begin(),total[i].end());
    int64_t cost=0;
    for(int k=0;k<S;k++){
      cost+=total[i][k];
    }
    if(i) printf(" ");
    printf("%I64d",cost);
  }
  printf("\n");
  return 0;
}