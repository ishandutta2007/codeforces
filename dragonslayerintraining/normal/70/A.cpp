#include <iostream>

int main(){
  int N;
  std::cin>>N;
  long long v=1;
  for(int i=1;i<N;i++){
    v=(v*3)%1000003;
  }
  std::cout<<v<<std::endl;
  return 0;
}