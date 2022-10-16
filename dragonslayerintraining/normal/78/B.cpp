#include <iostream>

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N-3;i++){
    std::cout<<"ROYG"[i%4];
  }
  for(int i=0;i<3;i++){
    std::cout<<"BIV"[i];
  }
  std::cout<<std::endl;
  return 0;
}