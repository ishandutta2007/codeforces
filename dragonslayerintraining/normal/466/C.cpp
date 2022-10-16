#include <cstdio>
#include <stdint.h>

int64_t as[500001];

int64_t dp[2];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    as[i]+=as[i-1];
  }
  if(as[N]/3*3!=as[N]){
    printf("0\n");
    return 0;
  }
  for(int i=1;i<N;i++){
    if(as[i]==as[N]/3*2){
      dp[1]+=dp[0];
    }
    if(as[i]==as[N]/3){
      dp[0]++;
    }
  }
  printf("%I64d\n",dp[1]);
  return 0;
}