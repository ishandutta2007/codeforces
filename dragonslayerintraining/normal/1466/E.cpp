#include <cstdio>

const long long MOD=1e9+7;

long long xs[500005];
long long pow2[61];

void solve(){
  long long N;
  scanf("%lld",&N);
  long long pop[60]={};
  for(long long i=0;i<N;i++){
    scanf("%lld",&xs[i]);
  }
  for(long long i=0;i<N;i++){
    for(long long k=0;k<60;k++){
      if((xs[i]>>k)&1){
	pop[k]++;
      }
    }
  }
  long long ans=0;
  for(long long i=0;i<N;i++){
    long long a=0,b=0;
    for(long long k=0;k<60;k++){
      if((xs[i]>>k)&1){
	a=(a+1LL*pop[k]*pow2[k])%MOD;
	b=(b+1LL*N*pow2[k])%MOD;
      }else{
	b=(b+1LL*pop[k]*pow2[k])%MOD;
      }
    }
    ans=(ans+1LL*a*b)%MOD;
  }
  printf("%lld\n",ans);
}

int main(){
  pow2[0]=1;
  for(long long k=1;k<60;k++){
    pow2[k]=pow2[k-1]*2LL%MOD;
  }
  long long T;
  scanf("%lld",&T);
  while(T--){
    solve();
  }
}