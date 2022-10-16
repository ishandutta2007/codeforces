#include <iostream>

int main(){
  int N,K,T;
  std::cin>>N>>K>>T;
  if(T<=K){
    std::cout<<T<<std::endl;
  }else if(T>N){
    std::cout<<N+K-T<<std::endl;
  }else{
    std::cout<<K<<std::endl;
  }
  return 0;
}