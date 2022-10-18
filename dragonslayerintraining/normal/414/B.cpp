#include <cstdio>

const int MOD=1e9+7;


int dp[2001];
int next[2001];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  dp[1]=1;
  for(int k=1;k<=K;k++){
    for(int i=1;i<=N;i++){
      for(int j=i;j<=N;j+=i){
	next[j]=(next[j]+dp[i])%MOD;
      }
    }
    for(int i=1;i<=N;i++){
      dp[i]=next[i];
      next[i]=0;
    }
    /*
      for(int i=1;i<=N;i++){
      printf("%d:%d\n",i,dp[i]);
      }
    */
  }
  int sum=0;
  for(int i=1;i<=N;i++){
    sum=(sum+dp[i])%MOD;
  }
  printf("%d\n",sum);
  return 0;
}