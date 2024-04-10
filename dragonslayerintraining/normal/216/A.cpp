#include <iostream>

int tri(int N){
  return N*(N+1)/2;
}

int main(){
  int A,B,C;
  std::cin>>A>>B>>C;
  std::cout<<tri(A+B+C-2)-tri(A-1)-tri(B-1)-tri(C-1)<<std::endl;
  return 0;
}