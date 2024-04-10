#include <cstdio>
#include <stdint.h>

int64_t as[200005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    as[i]+=as[i-1];
  }
  int64_t sum=0;
  for(int i=0;i+K<=N;i++){
    sum+=as[i+K]-as[i];
  }
  printf("%.10f\n",double(sum)/(N-K+1));
  return 0;
}