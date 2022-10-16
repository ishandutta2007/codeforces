#include <iostream>

int main(){
  int N,K;
  std::cin>>N>>K;
  if(N<3*K){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(int i=1;i<=K;i++){
    if(i>1){
      std::cout<<" ";
    }
    std::cout<<i;
  }
  for(int i=1;i<=K;i++){
    std::cout<<" "<<i<<" "<<i;
  }
  for(int i=K*3;i<N;i++){
    std::cout<<" 1";
  }
  std::cout<<std::endl;
  return 0;
}