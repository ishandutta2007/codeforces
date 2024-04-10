#include <iostream>

int gcd(int a,int b){
  return (b==0)?a:gcd(b,a%b);
}

int main(){
  int A,B,N;
  std::cin>>A>>B>>N;
  while(true){
    if(N==0){
      std::cout<<1<<std::endl;
      break;
    }
    N-=gcd(N,A);
    if(N==0){
      std::cout<<0<<std::endl;
      break;
    }
    N-=gcd(N,B);
  }
  return 0;
}