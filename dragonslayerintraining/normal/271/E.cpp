#include <iostream>
#include <stdint.h>

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int main(){
  int64_t N,M;
  std::cin>>N>>M;
  int64_t R=0;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    R=gcd(R,A-1);
  }
  while(R%2==0){
    R/=2;
  }
  int64_t cnt=0;
  for(int64_t i=1;;i++){
    if(R%i==0){
      for(int64_t F=i;F<M;F*=2){
	cnt+=M-F;
      }
    }
    if(i*i>=R){
      break;
    }
    if(R%i==0){
      for(int64_t F=R/i;F<M;F*=2){
	cnt+=M-F;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}