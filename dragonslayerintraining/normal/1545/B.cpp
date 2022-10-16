#include <cstdio>

const int MOD=998244353;

char str[100005];

int modexp(int base,int exp){
  int res=1;
  for(;exp;exp>>=1){
    if(exp&1) res=1LL*res*base%MOD;
    base=1LL*base*base%MOD;
  }
  return res;
}

void solve(){
  int N;
  scanf("%d",&N);
  scanf("%s",str);
  int odd=0;
  int zeros=0;
  int ones=0;
  int run=0;
  for(int i=0;i<N;i++){
    zeros+=(str[i]=='0');
    ones+=(str[i]=='1');
    if(str[i]=='1'){
      run++;
    }else{
      if(run%2==1){
	odd++;
      }
      run=0;
    }
  }
  if(run%2==1){
    odd++;
  }
  int pairs=(ones-odd)/2;
  int ans=1;
  for(int i=0;i<zeros;i++){
    ans=1LL*ans*(pairs+zeros-i)%MOD*modexp(i+1,MOD-2)%MOD;
  }
  printf("%d\n",ans);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}