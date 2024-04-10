#include <cstdio>
#include <algorithm>
#include <stdint.h>

int ls[100005];
int rs[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&ls[i],&rs[i]);
  }
  std::sort(ls,ls+N);
  std::sort(rs,rs+N);
  int64_t cost=N;
  for(int i=0;i<N;i++){
    cost+=std::max(ls[i],rs[i]);
  }
  printf("%I64d\n",cost);
  return 0;
}