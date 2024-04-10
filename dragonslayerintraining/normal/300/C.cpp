#include <cstdio>
#include <queue>
#include <stdint.h>

int A,B;
std::queue<int> good;

const int64_t MOD=1e9+7;

int64_t fact[1000005]={1,1};
int64_t inv[1000005]={0,1};
int64_t invfact[1000005]={1,1};

int main(){
  int N;
  scanf("%d %d %d",&A,&B,&N);
  for(int i=2;i<=N;i++){
    fact[i]=(i*fact[i-1])%MOD;
    inv[i]=(MOD-inv[MOD%i])*(MOD/i)%MOD;
    invfact[i]=(inv[i]*invfact[i-1])%MOD;
  }
  int64_t cnt=0;
  good.push(A);
  good.push(B);
  while(good.front()<=N*B){
    int64_t S=good.front();
    good.pop();
    good.push(S*10+A);
    good.push(S*10+B);
    if((S>=N*A)&&((S-N*A)%(B-A)==0)){
      int64_t K=(S-N*A)/(B-A);
      cnt+=fact[N]*invfact[K]%MOD*invfact[N-K]%MOD;
    }
  }
  printf("%I64d\n",cnt%MOD);
  return 0;
}