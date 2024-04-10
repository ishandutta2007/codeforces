#include <cstdio>
#include <stdint.h>

int main(){
  int64_t N;
  scanf("%I64d",&N);
  if(N==0){
    printf("0\n");
    return 0;
  }
  N++;
  if(N%2==0) N/=2;
  printf("%I64d\n",N);
  return 0;
}