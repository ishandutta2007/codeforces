#include <iostream>

int as[1000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int i=1;i<N;i++){
    if((as[i]+as[i-1])%N!=(i*2-1)%N){
      std::cout<<"No"<<std::endl;
      return 0;
    }
  }
  std::cout<<"Yes"<<std::endl;
  return 0;
}