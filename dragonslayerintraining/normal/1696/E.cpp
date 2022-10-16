#include <cstdio>

const int MOD=1e9+7;

int N;
int as[200005];

int inv[400005]={0,1};
int fact[400005]={1,1};
int invfact[400005]={1,1};

int combo(int a,int b){
  //printf("combo(%d,%d)\n",a,b);
  if(a<0||b<0) return 0;
  return 1LL*fact[a+b]*invfact[a]%MOD*invfact[b]%MOD;
}

int main(){
  for(int i=2;i<=400000;i++){
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    fact[i]=1LL*i*fact[i-1]%MOD;
    invfact[i]=1LL*inv[i]*invfact[i-1]%MOD;
  }
  scanf("%d",&N);
  for(int i=0;i<=N;i++){
    scanf("%d",&as[i]);
  }
  int cnt=0;
  for(int i=1;i<=N+1;i++){
    cnt=(cnt+combo(i,as[i-1]-1))%MOD;
  }
  printf("%d\n",cnt);
}