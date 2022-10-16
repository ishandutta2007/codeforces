#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[300005];
int64_t bs[300005];

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  int64_t trail=0;
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&bs[i]);
  }
  for(int64_t i=0;i<N;i++){
    int64_t x=std::max<int64_t>(0,trail)+as[i]-K*bs[i];
    int64_t y=std::max<int64_t>(0,-trail)+bs[i]-K*as[i];
    if(x>0){
      trail=x;
    }else if(y>0){
      trail=-y;
    }else{
      trail=0;
    }
    if(std::abs(trail)>K){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}