#include <cstdio>
#include <stdint.h>

const int MOD=1e9+7;

int64_t ps[100005];

int64_t cost[100005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&ps[i]);
  }
  for(int64_t i=1;i<=N;i++){
    cost[i]=(2+cost[i-1]*2-cost[ps[i]-1]+MOD)%MOD;
  }
  printf("%I64d\n",cost[N]);
  return 0;
}