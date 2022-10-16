#include <iostream>

int main(){
  int N;
  std::cin>>N;
  std::cout<<N;
  for(int i=1;i<N;i++){
    std::cout<<" "<<i;
  }
  std::cout<<std::endl;
  return 0;
}