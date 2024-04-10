#include <cstdio>
#include <stdint.h>

const int MOD=1e9+7;

int ts[200005];

int fact[200005]={1,1};
int inv[200005]={0,1};
int invfact[200005]={1,1};

int choose(int a,int b){
  if(b<0||b>a) return 0;
  return 1LL*fact[a]*invfact[b]%MOD*invfact[a-b]%MOD;
}

int main(){
  for(int i=2;i<=200000;i++){
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    fact[i]=1LL*fact[i-1]*i%MOD;
    invfact[i]=1LL*invfact[i-1]*inv[i]%MOD;
  }
  int N;
  int64_t T;
  scanf("%d %I64d",&N,&T);
  for(int i=0;i<N;i++){
    scanf("%d",&ts[i]);
  }
  int ans=0;
  int den=1;
  int x=0;
  int prefix=1;
  for(int i=0;i<N;i++){
    T-=ts[i];
    den=1LL*den*inv[2]%MOD;
    prefix=(prefix*2LL+choose(i,++x))%MOD;
    
    if(T<0) break;
    if(T>i+1){
      ans=(ans+1)%MOD;
    }else{
      //add (i+1 \choose \le T)/2^(i+1)
      while(x>T){
	prefix=(prefix-choose(i+1,x--)+MOD)%MOD;
      }
      ans=(ans+1LL*prefix*den)%MOD;
    }
  }
  printf("%d\n",ans);
  return 0;
}