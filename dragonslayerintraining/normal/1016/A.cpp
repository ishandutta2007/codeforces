#include <cstdio>
#include <stdint.h>

int64_t as[200005];

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    as[i]+=as[i-1];
  }
  for(int64_t i=1;i<=N;i++){
    if(i>1) printf(" ");
    printf("%I64d",as[i]/M-as[i-1]/M);
  }
  printf("\n");
  return 0;
}