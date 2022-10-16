#include <iostream>

bool isprime(int num){
  if(num<2){
    return false;
  }
  for(int i=2;i*i<=num;i++){
    if(num%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int N;
  std::cin>>N;
  for(int M=1;;M++){
    if(!isprime(N*M+1)){
      std::cout<<M<<std::endl;
      return 0;
    }
  }
}