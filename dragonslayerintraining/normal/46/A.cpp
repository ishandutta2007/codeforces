#include <iostream>

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<N;i++){
    if(i>1){
      std::cout<<" ";
    }
    std::cout<<(i*(i+1)/2)%N+1;
  }
  std::cout<<std::endl;
  return 0;
}