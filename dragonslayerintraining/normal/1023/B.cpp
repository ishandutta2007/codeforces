#include <cstdio>
#include <algorithm>
#include <stdint.h>

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  int64_t ans=std::max<int64_t>(0,std::min<int64_t>(N,K-1)-std::max<int64_t>(1,K-N)+1)/2;
  printf("%I64d\n",ans);
  return 0;
}