#include <iostream>

int main(){
  int N;
  std::cin>>N;
  if(N%2==0){
    std::cout<<-1<<std::endl;
  }else{
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<i;
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<(i+1)%N;
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<(i*2+1)%N;
    }
    std::cout<<std::endl;
  }
  return 0;
}