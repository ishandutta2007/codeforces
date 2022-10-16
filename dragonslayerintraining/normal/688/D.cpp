#include <cstdio>
#include <stdint.h>

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  int64_t lcm=1;
  for(int64_t i=0;i<N;i++){
    int64_t C;
    scanf("%I64d",&C);
    lcm=gcd(lcm*C/gcd(lcm,C),K);
  }
  if(lcm==K){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}