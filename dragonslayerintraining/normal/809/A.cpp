#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t xs[300000];

int main(){
  int N;
  scanf("%d",&N);
  for(int64_t i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    xs[i]=X;
  }
  std::sort(xs,xs+N);
  for(int64_t i=N-1;i>0;i--){
    xs[i]-=xs[i-1];
  }
  int64_t total=0;
  int64_t curr=0;
  int64_t powtwo=1;
  for(int64_t i=0;i<N;i++){
    curr=(curr*2+((powtwo+MOD-1)%MOD)*xs[i])%MOD;
    total=(total+curr)%MOD;
    powtwo=(powtwo*2)%MOD;
  }
  printf("%d\n",int(total));
  return 0;
}