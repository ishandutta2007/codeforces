#include <iostream>

int main(){
  int D,N;
  int sum=0;
  std::cin>>D>>N;
  for(int i=0;i<N-1;i++){
    int A;
    std::cin>>A;
    sum+=D-A;
  }
  std::cout<<sum<<std::endl;
  return 0;
}