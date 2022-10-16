#include <iostream>
#include <cmath>

int main(){
  int N;
  std::cin>>N;
  int sum=0;
  while(N-->0){
    int A;
    std::cin>>A;
    sum+=std::abs(A);
  }
  std::cout<<sum<<std::endl;
  return 0;
}