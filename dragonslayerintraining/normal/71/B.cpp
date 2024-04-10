#include <iostream>

int main(){
  int N,K,T;
  std::cin>>N>>K>>T;
  T=T*N*K/100;
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<std::min(T,K);
    T-=std::min(T,K);
  }
  std::cout<<std::endl;
  return 0;
}