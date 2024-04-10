#include <iostream>

int main(){
  long long N,K;
  std::cin>>N>>K;
  if(K>(N+1)/2){
    std::cout<<(K-(N+1)/2)*2<<std::endl;
  }else{
    std::cout<<K*2-1<<std::endl;
  }
  return 0;
}