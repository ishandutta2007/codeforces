#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[200000];

int main(){
  int64_t N,Q;
  scanf("%I64d %I64d",&N,&Q);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
    if(i) as[i]+=as[i-1];
  }
  int64_t arrows=0;
  for(int64_t i=0;i<Q;i++){
    int64_t K;
    scanf("%I64d",&K);
    arrows+=K;
    int64_t index=std::upper_bound(as,as+N,arrows)-as;
    if(index==N){
      index=0;
      arrows=0;
    }
    printf("%I64d\n",N-index);
  }
  return 0;
}