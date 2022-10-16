#include <cstdio>
#include <algorithm>
#include <stdint.h>

int main(){
  int64_t N;
  scanf("%I64d",&N);
  int64_t low=0,high=5e17;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    int64_t left=N;
    int64_t V=0;
    while(left>0){
      V+=std::min(left,mid);
      left-=std::min(left,mid);
      left-=left/10;
    }
    if(V*2>=N){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%I64d\n",high);
  return 0;
}