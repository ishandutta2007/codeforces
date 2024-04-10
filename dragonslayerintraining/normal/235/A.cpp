#include <iostream>
#include <stdint.h>

int64_t gcd(int64_t a,int64_t b){
  return (b==0)?a:gcd(b,a%b);
}

int64_t lcm(int64_t a,int64_t b){
  return a/gcd(a,b)*b;
}

int main(){
  int N;
  int64_t best=1;
  std::cin>>N;
  for(int i=std::max(1,N-100);i<=N;i++){
    for(int j=std::max(1,N-100);j<=N;j++){
      for(int k=std::max(1,N-100);k<=N;k++){
	best=std::max(best,lcm(i,lcm(j,k)));
      }
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}