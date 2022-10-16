#include <iostream>

int main(){
  int N,K;
  std::cin>>N>>K;
  while(K-->0){
    if(N%10==0) N/=10; else N--;
  }
  std::cout<<N<<std::endl;
  return 0;
}