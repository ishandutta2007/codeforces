#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[100005];

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  std::sort(as,as+N);
  int64_t high=0;
  int64_t cost=0;
  for(int64_t i=0;i<N;i++){
    cost+=as[i];
    cost--;
    high=std::min(high+1,as[i]);
  }
  printf("%I64d\n",cost-(as[N-1]-high));
  return 0;
}