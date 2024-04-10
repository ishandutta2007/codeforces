#include <cstdio>
#include <algorithm>
#include <stdint.h>

std::pair<int64_t,int64_t> xs[300005];

int64_t prefix[300005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&xs[i].first);
    xs[i].second=i;
  }
  std::sort(xs+1,xs+N+1);
  for(int64_t i=1;i<=N;i++){
    prefix[i]=xs[i].first+prefix[i-1];
  }
  int64_t K;
  scanf("%I64d",&K);
  int64_t cost=0;
  for(int64_t i=1;i<=K;i++){
    cost+=(i*2-K-1)*xs[i].first;
  }
  //printf("COST[0,%I64d)=%I64d\n",K,cost);
  std::pair<int64_t,int64_t> best(cost,1);
  for(int64_t i=K;i<N;i++){
    //printf("-%I64d\n",(prefix[i]-prefix[i-K])*2);
    cost-=(prefix[i]-prefix[i-K])*2;
    //printf("+%I64d*%I64d\n",K+1,xs[i-K+1].first);
    cost+=(K+1)*xs[i-K+1].first;
    //printf("+%I64d*%I64d\n",K-1,xs[i+1].first);
    cost+=(K-1)*xs[i+1].first;
    //printf("COST[%I64d,%I64d)=%I64d\n",i-K+1,i+1,cost);
    best=std::min(best,std::make_pair(cost,i-K+2));
  }
  //printf("best.second=%I64d\n",best.second);
  for(int64_t i=0;i<K;i++){
    if(i) printf(" ");
    printf("%I64d",xs[best.second+i].second);
  }
  printf("\n");
  return 0;
}