#include <iostream>


int main(){
  int N,M;
  std::cin>>N>>M;
  int k=(N+M*2-1)/2/M*M;
  if(k<=N){
    std::cout<<k<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}