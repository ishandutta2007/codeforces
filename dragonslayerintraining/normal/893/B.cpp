#include <cstdio>
#include <stdint.h>

int main(){
  int N;
  scanf("%d",&N);
  for(int k=20;k>0;k--){
    int64_t div=((1LL<<k)-1)*(1LL<<(k-1));
    if(N%div==0){
      printf("%I64d\n",div);
      return 0;
    }
  }
  return 0;
}