#include <iostream>

int main(){
  int K;
  std::cin>>K;
  int max=0;
  for(int i=0;i<K;i++){
    int A;
    std::cin>>A;
    max=std::max(max,A);
  }
  std::cout<<std::max(0,max-25)<<std::endl;
  return 0;
}