#include <iostream>

int main(){
  int N,M,K;
  std::cin>>N>>M>>K;
  K--;
  std::cout<<K/(2*M)+1<<" "<<K/2%M+1<<" "<<((K%2)?'R':'L')<<std::endl;
  return 0;
}