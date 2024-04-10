#include <cstdio>

const int MOD=998244353;

int hs[200005];
int mem[200005];
int* poly=mem+2;

int modpow(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int inverse(int x){
  int inv=modpow(x,MOD-2);
  return inv;
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&hs[i]);
  }
  int diff=0;
  for(int i=0;i<N;i++){
    diff+=(hs[i]!=hs[(i+1)%N]);
  }
  poly[0]=1;
  for(int i=1;i<diff;i++){
    poly[i]=-(poly[i-2]*1LL%MOD*((i-2)-2*diff)%MOD+
	      poly[i-1]*(K-2LL)%MOD*((i-2)-diff+1)%MOD)*inverse(i)%MOD;
  }
  int ans=0;
  for(int i=0;i<diff;i++){
    //printf("poly[%d]=%d\n",i,poly[i]);
    ans=(ans+poly[i])%MOD;
  }
  for(int i=0;i<N-diff;i++){
    ans=1LL*ans*K%MOD;
  }
  printf("%d\n",(ans+MOD)%MOD);
}