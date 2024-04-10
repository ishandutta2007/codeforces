#include <iostream>

int holidays[400];

int main(){
  int N,K,C;
  std::cin>>N>>K>>C;
  for(int i=0;i<C;i++){
    std::cin>>holidays[i];
  }
  holidays[C++]=1e9;
  int *next=holidays;
  int cnt=0;
  for(int i=0;i<=N;i=std::min(*next,i+K)){
    //std::cerr<<"i="<<i<<std::endl;
    if(i>=*next){
      next++;
    }
    if(i>0){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}