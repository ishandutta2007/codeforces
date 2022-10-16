#include <cstdio>
#include <stdint.h>

bool solve(int64_t A,int64_t B){
  if(A-B!=1){
    return false;
  }
  int64_t C=A+B;
  for(int64_t i=2;i*i<=C;i++){
    if(C%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int64_t T;
  scanf("%I64d",&T);
  while(T-->0){
    int64_t A,B;
    scanf("%I64d %I64d",&A,&B);
    if(solve(A,B)){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}