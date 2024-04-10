#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  int D=std::min(N,M);
  std::cout<<D+1<<std::endl;
  for(int i=0;i<=D;i++){
    std::cout<<i<<" "<<(D-i)<<std::endl;
  }
  return 0;
}