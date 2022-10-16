#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int N;

int as[505];

int dp[505];

char ts[505];
int xs[505];

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf(" %c",&ts[i]);
    if(ts[i]=='+'){
      scanf("%d",&xs[i]);
    }
  }
  int total=0;
  for(int i=0;i<N;i++){
    if(ts[i]=='-') continue;
    std::fill(dp,dp+N,0);
    dp[0]=1;
    for(int j=0;j<N;j++){
      if(j==i) continue;
      if(ts[j]=='+'){
	if(std::make_pair(xs[j],j)<std::make_pair(xs[i],i)){
	  for(int k=N-1;k>0;k--){
	    dp[k]=(dp[k]+dp[k-1])%MOD;
	  }
	}else{
	  for(int k=N-1;k>=0;k--){
	    dp[k]=dp[k]*2%MOD;
	  }
	}
      }else{
	if(j<i) dp[0]=dp[0]*2%MOD;
	for(int k=0;k<N-1;k++){
	  dp[k]=(dp[k]+dp[k+1])%MOD;
	}
      }
    }
    int sum=0;
    for(int k=0;k<N;k++){
      //printf("%d: %d\n",i,dp[k]);
      sum=(sum+dp[k])%MOD;
    }
    total=(total+1LL*sum*xs[i])%MOD;
  }
  printf("%d\n",total);
}