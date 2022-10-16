#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int ac=0;
  for(int i=1;i<=N;i++){
    ac+=i*(N-i)+1;
  }
  std::cout<<ac<<std::endl;
  return 0;
}