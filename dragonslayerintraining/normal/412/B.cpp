#include <iostream>
#include <algorithm>

int as[100];

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  std::cout<<as[N-K]<<std::endl;
  return 0;
}