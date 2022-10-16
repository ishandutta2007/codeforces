#include <cstdio>
#include <stdint.h>

int main(){
  int64_t L,R;
  scanf("%I64d %I64d",&L,&R);
  printf("YES\n");
  for(int64_t i=L;i<R;i+=2){
    printf("%I64d %I64d\n",i,i+1);
  }
  return 0;
}