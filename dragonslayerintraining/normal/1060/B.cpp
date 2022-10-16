#include <cstdio>
#include <stdint.h>

int main(){
  int64_t N;
  scanf("%I64d",&N);
  int ans=0;
  for(;N%10==9;N/=10){
    ans+=9;
  }
  for(;N>=10;N/=10){
    ans+=N%10+9;
  }
  ans+=N;
  printf("%d\n",ans);
  return 0;
}