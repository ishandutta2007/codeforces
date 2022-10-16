#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t dp[5];

int main(){
  int N,X;
  scanf("%d %d",&N,&X);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    dp[1]+=A;
    dp[2]+=1LL*A*X;
    dp[3]+=A;
    for(int i=0;i<4;i++){
      dp[i+1]=std::max(dp[i+1],dp[i]);
    }
  }
  printf("%I64d\n",dp[4]);
  return 0;
}