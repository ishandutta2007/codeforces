#include <iostream>

int as[100000];

int main(){
  int N,K;
  std::cin>>N>>K;
  K--;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int i=K;i<N;i++){
    if(as[K]!=as[i]){
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  for(int i=K-1;i>=0;i--){
    if(as[i]!=as[K]){
      std::cout<<i+1<<std::endl;
      return 0;
    }
  }
  std::cout<<0<<std::endl;
}