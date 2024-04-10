#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int xs[200005];
int ys[200005];
int ss[200005];

int dp[200005];
int sum[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d %d %d",&xs[i],&ys[i],&ss[i]);
  }
  int ans=(xs[N]+1)%MOD;
  for(int i=1;i<=N;i++){
    int j=std::lower_bound(xs,xs+N,ys[i])-xs;
    dp[i]=(((xs[i]-ys[i])+sum[i-1])%MOD+MOD-sum[j-1])%MOD;
    sum[i]=(sum[i-1]+dp[i])%MOD;
    if(ss[i]){
      ans=(ans+dp[i])%MOD;
    }
  }
  printf("%d\n",ans);
}