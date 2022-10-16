#include <iostream>
#include <stdint.h>

int as[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    as[A]=i+1;
  }
  int M;
  std::cin>>M;
  int64_t V=0;
  for(int i=0;i<M;i++){
    int B;
    std::cin>>B;
    V+=as[B];
  }
  std::cout<<V<<" "<<M*int64_t(N+1)-V<<std::endl;
  return 0;
}