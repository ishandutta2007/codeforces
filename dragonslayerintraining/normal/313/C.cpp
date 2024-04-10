#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[2000000];

int64_t log4(int64_t num){
  int64_t cnt=0;
  for(;num>0;num/=4){
    cnt++;
  }
  return cnt;
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  std::sort(as,as+N);
  std::reverse(as,as+N);
  int64_t total=0;
  for(int64_t i=0;i<N;i++){
    total+=(log4(N)-log4(i))*as[i];
  }
  printf("%I64d\n",total);
  return 0;
}