#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t MOD=1e9+7;
const int64_t HALF=5e8+4;

//|_N/x_|=k
//k<=N/x<k+1
//kx<=N<kx+x
//x<=N/k

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  int64_t ans=0;
  for(int64_t i=1,j;i<=std::min(N,M);i=j+1){
    int64_t k=N/i;
    j=std::min(std::min(N,M),N/k);
    ans=(ans+(j-i+1)%MOD*((i+j)%MOD)%MOD*HALF%MOD*(k%MOD))%MOD;
  }
  printf("%I64d\n",(N%MOD*(M%MOD)%MOD-ans+MOD)%MOD);
}