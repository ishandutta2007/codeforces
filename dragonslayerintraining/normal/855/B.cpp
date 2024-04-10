#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t N;
int64_t ps[4];
int64_t maxs[4];

int main(){
  std::fill(maxs+1,maxs+4,-4e18);

  scanf("%I64d",&N);
  for(int64_t i=1;i<=3;i++){
    scanf("%I64d",&ps[i]);
  }
 
  for(int64_t k=0;k<N;k++){
    int64_t A;
    scanf("%I64d",&A);
    for(int64_t i=1;i<=3;i++){
      maxs[i]=std::max(maxs[i],maxs[i-1]+A*ps[i]);
    }
  }
  printf("%I64d\n",maxs[3]);
  return 0;
}