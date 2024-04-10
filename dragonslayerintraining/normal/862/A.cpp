#include <iostream>

int main(){
  int N,X;
  std::cin>>N>>X;
  int evil=X;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    evil+=(A==X)-(A<X);
  }
  std::cout<<evil<<std::endl;
  return 0;
}