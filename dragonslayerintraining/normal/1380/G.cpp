#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int modexp(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int cs[300005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&cs[i]);
  }
  std::sort(cs+1,cs+N+1);
  for(int i=1;i<=N;i++){
    cs[i]=(cs[i]+cs[i-1])%MOD;
  }
  int den=modexp(N,MOD-2);
  for(int k=1;k<=N;k++){
    int sum=0;
    for(int i=N-k;i>0;i-=k){
      sum=(sum+cs[i])%MOD;
    }
    int ans=1LL*sum*den%MOD;
    printf("%d\n",ans);
  }
}