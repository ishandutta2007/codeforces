#include <iostream>
#include <algorithm>

int main(){
  int N,M;
  std::cin>>N>>M;
  int X=std::min(N,M);
  std::cout<<((X%2)?"Akshat":"Malvika")<<std::endl;
  return 0;
}