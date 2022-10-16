#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int modpow(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int as[5001];
int fs[5001];

int dp[5001];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int K=0;
  for(int i=0;i<N;i++){
    if(i==N-1||as[i]!=as[i+1]){
      fs[++K]=i+1;
    }
  }
  std::fill(dp,dp+K+1,0);
  dp[0]=1;
  for(int i=0;i<N/2;i++){
    //even
    for(int i=0;i<K;i++){
      dp[i+1]=(dp[i+1]+dp[i])%MOD;
    }
    for(int i=K;i>0;i--){
      dp[i]=1LL*(fs[i]-fs[i-1])*dp[i-1]%MOD;
    }
    dp[0]=0;
    if(i==0){
      //odd 1
      for(int j=1;j<=K;j++){
	int rem=std::max(0,fs[j-1]);
	dp[j]=(1LL*dp[j]*rem)%MOD;
      }
    }
    if(i<N/2-1){
      //odd
      for(int j=1;j<=K;j++){
	int rem=std::max(0,fs[j-1]-i*2-1);
	dp[j]=(1LL*dp[j]*rem)%MOD;
      }
    }
  }
  int den=1;
  for(int i=1;i<=K;i++){
    int k=fs[i]-fs[i-1];
    for(int j=1;j<=k;j++){
      den=1LL*den*j%MOD;
    }
  }
  printf("%lld\n",1LL*dp[K]*modpow(den,MOD-2)%MOD);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}