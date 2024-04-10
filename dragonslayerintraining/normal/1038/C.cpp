#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[200005];

int main(){
  int N;
  scanf("%d",&N);
  int64_t ans=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    ans+=as[i];
  }
  for(int i=0;i<N;i++){
    scanf("%d",&as[i+N]);
    ans-=as[i+N];
  }
  std::sort(as,as+N*2);
  for(int i=0;i<N*2;i++){
    if(i&1){
      ans+=as[i];
    }else{
      ans-=as[i];
    }
  }
  printf("%I64d\n",ans/2);
  return 0;
}