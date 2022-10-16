#include <cstdio>
#include <stdint.h>

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t P,Q,B;
    scanf("%I64d %I64d %I64d",&P,&Q,&B);
    Q/=gcd(P,Q);
    while(B>1){
      while(Q%B==0){
	Q/=B;
      }
      B=gcd(Q,B);
    }
    if(Q==1){
      printf("Finite\n");
    }else{
      printf("Infinite\n");
    }
  }
  return 0;
}