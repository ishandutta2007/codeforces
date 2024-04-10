#include <cstdio>
#include <algorithm>
#include <stdint.h>

int main(){
  int64_t N;
  scanf("%I64d",&N);
  if(N<5){
    printf("%I64d\n",N*(N-1)/2);
    return 0;
  }
  int64_t pow10=1;
  while(pow10*10<=2*N){
    pow10*=10;
  }
  //printf("pow10=%I64d\n",pow10);
  int64_t total=0;
  for(int64_t c=1;c*pow10<=2*N;c++){
    int64_t sum=c*pow10-1;
    total+=(std::min(sum-1,2*N-sum+1)+1)/2;
  }
  printf("%I64d\n",total);
  return 0;
}