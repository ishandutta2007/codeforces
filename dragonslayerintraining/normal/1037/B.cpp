#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[200005];

int main(){
  int N,S;
  scanf("%d %d",&N,&S);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  int64_t cost=0;
  for(int i=0;i<=N/2;i++){
    cost+=std::max(0,as[i]-S);
  }
  for(int i=N/2;i<N;i++){
    cost+=std::max(0,S-as[i]);
  }
  printf("%I64d\n",cost);
  return 0;
}