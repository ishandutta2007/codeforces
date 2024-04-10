#include <cstdio>

int dp[61]={1,0};

int main(){
  int N;
  scanf("%d",&N);
  for(int i=2;i<=N;i++){
    dp[i]=2*dp[i-2];
  }
  printf("%d\n",dp[N]);
  return 0;
}