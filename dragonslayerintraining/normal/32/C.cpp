#include <iostream>

int main(){
  long long N,M,S;
  std::cin>>N>>M>>S;
  long long x=(N+S-1)/S;
  long long y=(M+S-1)/S;
  long long x2=N%S,y2=M%S;
  x2=(x2==0)?S:x2;
  y2=(y2==0)?S:y2;
  std::cout<<x*y*x2*y2<<std::endl;
  return 0;
}