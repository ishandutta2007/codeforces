#include <cstdio>
#include <stdint.h>

int64_t N,K;
int main(){
  scanf("%I64d %I64d",&N,&K);
  N--,K--;
  N=K*(K+1)/2-N;
  if(N<0){
    printf("-1\n");
    return 0;
  }
  int64_t low=0,high=K+1;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(mid*(mid+1)/2>N){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%I64d\n",K-low);
  return 0;
}