#include <iostream>

int main(){
  int N,H;
  std::cin>>N>>H;
  int width=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    width+=1+(A>H);
  }
  std::cout<<width<<std::endl;
  return 0;
}