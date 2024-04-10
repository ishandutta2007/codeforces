#include <iostream>

int main(){
  int T;
  std::cin>>T;
  while(T--){
    int N,S;
    std::cin>>N>>S;
    std::cout<<S/(N/2+1)<<std::endl;
  }
}