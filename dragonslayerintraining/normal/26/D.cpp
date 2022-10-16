#include <iostream>

int main(){
  int N,M,K;
  std::cin>>N>>M>>K;
  if(K+N<M){
    std::cout<<0<<std::endl;
    return 0;
  }
  double ans=1;
  for(int i=0;i<=K;i++){
    ans*=(M-i);
    ans/=(N+i+1);
  }
  std::cout<<1-ans<<std::endl;
  return 0;
}