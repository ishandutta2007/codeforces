#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t deficiency(int64_t N,int64_t M){
  if(N>M) std::swap(N,M);
  if(N==1){
    int64_t tmp=M%6;
    return std::min(tmp,6-tmp);
  }
  if(N==2){
    if(M==2) return 4;
    if(M==3||M==7) return 2;
    return 0;
  }
  return (N&1)&&(M&1);
}

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  printf("%I64d\n",N*M-deficiency(N,M));
  return 0;
}