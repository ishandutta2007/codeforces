#include <iostream>

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cout<<char('a'+i%4);
  }
  std::cout<<std::endl;
  return 0;
}