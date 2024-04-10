#include <cstdio>
#include <algorithm>
#include <queue>
#include <stdint.h>

std::pair<int,int> songs[300005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d %d",&songs[i].second,&songs[i].first);
  }
  std::sort(songs,songs+N);
  int64_t sum=0;
  std::priority_queue<int> pq;
  int64_t best=0;
  for(int i=N-1;i>=0;i--){
    pq.push(-songs[i].second);
    sum+=songs[i].second;
    while(pq.size()>K){
      sum+=pq.top();
      pq.pop();
    }
    best=std::max<int64_t>(best,sum*songs[i].first);
  }
  printf("%I64d\n",best);
  return 0;
}