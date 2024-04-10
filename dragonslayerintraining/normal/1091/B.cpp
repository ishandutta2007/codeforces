#include <cstdio>
#include <stdint.h>

int main(){
  int64_t N;
  scanf("%I64d",&N);
  int64_t XX=0,YY=0;
  for(int64_t i=0;i<N*2;i++){
    int64_t X,Y;
    scanf("%I64d %I64d",&X,&Y);
    XX+=X,YY+=Y;
  }
  printf("%I64d %I64d\n",XX/N,YY/N);
  return 0;
}