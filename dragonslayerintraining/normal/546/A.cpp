#include <iostream>
#include <algorithm>

int main(){
  int K,N,W;
  std::cin>>K>>N>>W;
  std::cout<<std::max((W*(W+1)/2)*K-N,0)<<std::endl;
  return 0;
}