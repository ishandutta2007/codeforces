#include <cstdio>
#include <stdint.h>
#include <algorithm>

int main(){
  int64_t A,B,C;
  scanf("%I64d %I64d %I64d",&A,&B,&C);
  int64_t x=std::min(A,B);
  A-=x;
  B-=x;
  C+=x;
  printf("%I64d\n",C*2+(A||B));
  return 0;
}