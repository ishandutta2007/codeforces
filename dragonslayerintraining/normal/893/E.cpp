#include <cstdio>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t* minfactor;

int64_t* fact;
int64_t* inv;
int64_t* invfact;
int64_t* pow2;

int main(){
  minfactor=new int64_t[1000001];
  fact=new int64_t[2000001];
  fact[0]=1;
  inv=new int64_t[1000001];
  inv[0]=0;
  inv[1]=1;
  invfact=new int64_t[1000001];
  invfact[0]=1;
  pow2=new int64_t[1000001];
  pow2[0]=1;
  for(int64_t i=2;i<=1000000;i++){
    if(minfactor[i]==0){
      for(int64_t k=i;k<=1000000;k+=i){
	minfactor[k]=i;
      }
    }
  }
  for(int64_t i=2;i<=1000000;i++){
    inv[i]=(MOD-inv[MOD%i])*(MOD/i)%MOD;
  }
  for(int64_t i=1;i<=2000000;i++){
    fact[i]=fact[i-1]*i%MOD;
  }
  for(int64_t i=1;i<=1000000;i++){
    invfact[i]=invfact[i-1]*inv[i]%MOD;
    pow2[i]=pow2[i-1]*2%MOD;
  }

  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    int64_t ways=1;
    while(minfactor[X]>1){
      int64_t e=0;
      //printf("%d factor %I64d ",X,minfactor[X]);
      for(int64_t factor=minfactor[X];minfactor[X]==factor;X/=minfactor[X]){
	e++;
      }
      //printf("%I64dx %I64d ways\n",e,fact[e+Y-1]%MOD*invfact[e]%MOD*invfact[Y-1]%MOD);
      ways=ways*fact[e+Y-1]%MOD*invfact[e]%MOD*invfact[Y-1]%MOD;
    }
    printf("%I64d\n",ways*pow2[Y-1]%MOD);
  }
  
  return 0;
}