#include <cstdio>
#include <stdint.h>

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  printf("%I64d\n",(K+N-1)/N);
  return 0;
}