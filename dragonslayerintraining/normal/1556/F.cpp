#include <cstdio>

const int MOD=1e9+7;

int modpow(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int inverse(int x){
  return modpow(x,MOD-2);
}

int as[14];
int beat[14][14];

int scc[1<<14];

int dom[1<<14][14];//dom[S][x]: P(y beats x for all y in S)

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      beat[i][j]=1LL*as[i]*inverse(as[i]+as[j])%MOD;
    }
    beat[i][i]=0;
  }
  for(int mask=0;mask<(1<<N);mask++){
    for(int i=0;i<N;i++){
      int tmp=1;
      for(int j=0;j<N;j++){
	if(mask&(1<<j)){
	  tmp=1LL*tmp*beat[j][i]%MOD;
	}
      }
      dom[mask][i]=tmp;
    }
  }
  auto dominate=[&](int S,int T){
    int tmp=1;
    for(int i=0;i<N;i++){
      if(T&(1<<i)){
	tmp=1LL*tmp*dom[S][i]%MOD;
      }
    }
    return tmp;
  };
  int ans=0;
  for(int mask=1;mask<(1<<N);mask++){
    int tmp=1;
    for(int sub=(mask-1)&mask;sub;sub=(sub-1)&mask){
      tmp=(tmp-1LL*scc[sub]*dominate(sub,mask&~sub))%MOD;
    }
    scc[mask]=tmp;
    //printf("scc[%d]=%d\n",mask,scc[mask]);
    //case when mask is source SCC
    ans=(ans+1LL*__builtin_popcount(mask)*scc[mask]%MOD*dominate(mask,(1<<N)-1-mask))%MOD;
  }
  printf("%d\n",(ans+MOD)%MOD);
}