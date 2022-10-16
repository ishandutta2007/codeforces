#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int as[5005];
int bs[5005];
int cnt[5005];

int dp[5005][5005];

int fact[5005]={1,1};
int inv[5005]={0,1};
int invfact[5005]={1,1};

int main(){
  for(int i=2;i<=5000;i++){
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    fact[i]=1LL*i*fact[i-1]%MOD;
    invfact[i]=1LL*inv[i]*invfact[i-1]%MOD;
  }
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  std::copy(as,as+N,bs);
  int K=std::unique(bs,bs+N)-bs;
  for(int i=0;i<N;i++){
    cnt[std::lower_bound(bs,bs+K,as[i])-bs]++;
  }
  for(int x=0;x<K;x++){
    dp[1][x]=cnt[x];
  }
  for(int l=2;l<=N;l++){
    int prefix=0;
    for(int x=0;x<K;x++){
      dp[l][x]=1LL*prefix*cnt[x]%MOD;
      prefix=(prefix+dp[l-1][x])%MOD;
    }
  }
  int ans=0;
  for(int l=1;l<N;l++){
    for(int x=0;x<K;x++){
      ans=(ans+1LL*dp[l][x]*(cnt[x]-1)%MOD*fact[N-l-1])%MOD;
    }
  }
    printf("%d\n",int(1LL*ans*invfact[N]%MOD));
  return 0;
}