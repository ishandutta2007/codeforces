#include <iostream>
#include <algorithm>

int K;
int as[12];

int main(){
  std::cin>>K;
  for(int i=0;i<12;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+12);
  int sum=0;
  for(int i=0;i<12;i++){
    sum+=as[i];
  }
  if(sum<K){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(int i=0;i<12;i++){
    sum-=as[i];
    if(sum<K){
      std::cout<<12-i<<std::endl;
      return 0;
    }
  }
  std::cout<<0<<std::endl;
  return 0;
}