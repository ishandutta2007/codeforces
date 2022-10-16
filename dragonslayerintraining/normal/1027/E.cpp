#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int MOD=998244353;

int prefix[505];

int dp[505];

void addmod(int& x,int y){
  x=(x+y)%MOD;
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  dp[0]=1;
  for(int k=1;k<=N;k++){
    for(int i=1;i<=N;i++){
      dp[i]=0;
      for(int j=1;j<=std::min(i,k);j++){
	addmod(dp[i],dp[i-j]);
      }
    }
    prefix[k]=dp[N];
  }
  int j=N;
  int total=0;
  for(int i=1;i<=N;i++){
    while(i*j>=K) j--;
    addmod(total,int64_t(prefix[i]+MOD-prefix[i-1])*prefix[j]%MOD);
  }
  printf("%d\n",total*2%MOD);
  return 0;
}