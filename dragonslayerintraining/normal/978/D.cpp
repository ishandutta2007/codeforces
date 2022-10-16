#include <cstdio>
#include <algorithm>
#include <stdint.h>
#include <cmath>

int64_t bs[100000];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&bs[i]);
  }
  if(N<=2){
    printf("0\n");
    return 0;
  }
  int64_t diff0=bs[1]-bs[0]-2;
  int64_t diff1=bs[1]-bs[0]+2;
  int64_t best=1e9;
  for(int64_t start=bs[0]-1;start<=bs[0]+1;start++){
    for(int64_t diff=diff0;diff<=diff1;diff++){
      int64_t cost=0;
      for(int64_t i=0;i<N;i++){
	int64_t val=start+diff*i;
	if(std::abs(val-bs[i])<=1){
	  cost+=std::abs(val-bs[i]);
	}else{
	  cost=1e9;
	  break;
	}
      }
      best=std::min(best,cost);
    }
  }
  if(best<1e9){
    printf("%I64d\n",best);
  }else{
    printf("-1\n");
  }
  return 0;
}