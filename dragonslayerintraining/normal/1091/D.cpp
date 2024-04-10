#include <cstdio>
#include <stdint.h>

const int64_t MOD=998244353;

int64_t inv[1000005]={1,1};
int64_t fact[1000005]={1,1};
int64_t invfact[1000005]={1,1};

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=2;i<=N;i++){
    inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  for(int64_t i=2;i<=N;i++){
    fact[i]=fact[i-1]*i%MOD;
    invfact[i]=invfact[i-1]*inv[i]%MOD;
  }
  int64_t ans=1;
  for(int i=0;i<N;i++){
    ans=(ans+1+MOD-invfact[i])%MOD;
  }
  printf("%I64d\n",ans*fact[N]%MOD);
  return 0;
}