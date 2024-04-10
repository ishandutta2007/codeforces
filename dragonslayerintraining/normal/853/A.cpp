#include <cstdio>
#include <queue>
#include <stdint.h>

std::priority_queue<std::pair<int64_t,int>> costs;
int ans[300000];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  int64_t total=0;
  int64_t daily=0;
  for(int i=0;i<N+K;i++){
    if(i<N){
      int C;
      scanf("%d",&C);
      costs.emplace(C,i);
      daily+=C;
    }
    if(i>=K){
      daily-=costs.top().first;
      ans[costs.top().second]=i;
      costs.pop();
    }
    total+=daily;
  }
  printf("%I64d\n",total);
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",ans[i]+1);
  }
  printf("\n");
  return 0;
}