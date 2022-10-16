#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[200005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N*2;i++){
    scanf("%I64d",&as[i]);
  }

  std::sort(as,as+N*2);

  int64_t min=as[N*2-1]-as[0];
  for(int64_t i=1;i<N;i++){
    min=std::min(min,as[i+N-1]-as[i]);
  }
  printf("%I64d\n",std::min(min*(as[N*2-1]-as[0]),(as[N-1]-as[0])*(as[N*2-1]-as[N])));
  return 0;
}