#include <iostream>
#include <algorithm>

int as[200001]={1};

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=1;i<=N;i++){
    std::cin>>as[i];
  }
  std::sort(as+1,as+N+1);
  if(K==N||as[K]!=as[K+1]){
    std::cout<<as[K]<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}