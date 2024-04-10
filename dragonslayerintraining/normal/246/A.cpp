#include <iostream>

int main(){
  int N;
  std::cin>>N;
  if(N<=2){
    std::cout<<-1<<std::endl;
    return 0;
  }
  std::cout<<"2 3";
  for(int i=2;i<N;i++){
    std::cout<<" 1";
  }
  std::cout<<std::endl;
  return 0;
}