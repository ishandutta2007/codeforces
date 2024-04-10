#include <cstdio>
#include <algorithm>
#include <functional>
#include <stdint.h>

int64_t as[300005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int i=N-2;i>=0;i--){
    as[i]+=as[i+1];
  }
  std::sort(as+1,as+N,std::greater<int64_t>());
  int64_t ans=0;
  for(int i=0;i<K;i++){
    ans+=as[i];
  }
  printf("%I64d\n",ans);
  return 0;
}