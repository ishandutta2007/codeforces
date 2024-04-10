#include <iostream>
#include <algorithm>

int as[50];

int main(){
  int N,M,K;
  std::cin>>N>>M>>K;
  M-=K;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  std::reverse(as,as+N);
  for(int i=0;i<N;i++){
    if(M<=0){
      std::cout<<i<<std::endl;
      return 0;
    }
    M-=(as[i]-1);
  }
  if(M<=0){
    std::cout<<N<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}