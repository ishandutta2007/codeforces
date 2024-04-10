#include <cstdio>
#include <tuple>
#include <algorithm>
#include <stdint.h>

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  std::tuple<int64_t,int64_t,int64_t> best;
  for(int64_t i=0;i<K;i++){
    int64_t A;
    scanf("%I64d",&A);
    best=std::max(best,std::make_tuple(N/A*A,N/A,i+1));
  }
  printf("%I64d %I64d\n",std::get<2>(best),std::get<1>(best));
  return 0;
}