#include <cstdio>
#include <cassert>

const int MOD=1e9+7;

int inv[200005]={0,1};
int fact[200005]={1,1};
int invfact[200005]={1,1};

int choose(int n,int k){
  if(k<0||k>n) return 0;
  return 1LL*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}
int invchoose(int n,int k){
  if(k<0||k>n) return 0;
  return 1LL*invfact[n]*fact[k]%MOD*fact[n-k]%MOD;
}

void solve(){
  int ans=0;
  int N,K;
  scanf("%d %d",&N,&K);
  for(int l=0;N>=(l-1)*(K-1);l++){
    ans=(ans+1LL*invchoose(N,l)*choose(N-(l-1)*(K-1),l))%MOD;
    //printf("%d=>%d: %d ways\n",l,l+1,choose(N-(l-1)*(K-1),l));
  }
  printf("%d\n",ans);
}

int main(){
  for(int i=2;i<=200000;i++){
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    //printf("%lld\n",1LL*i*inv[i]%MOD);
    fact[i]=1LL*i*fact[i-1]%MOD;
    invfact[i]=1LL*inv[i]*invfact[i-1]%MOD;
    //printf("%lld\n",1LL*fact[i]*invfact[i]%MOD);
  }
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}