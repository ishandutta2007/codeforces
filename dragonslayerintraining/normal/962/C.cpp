#include <iostream>
#include <stdint.h>

const int64_t INF=1e9+7;

int64_t check(int64_t sub,int64_t whole){
  int64_t cost=0;
  for(;whole>0;whole/=10){
    if(sub>0&&(whole%10==sub%10)){
      sub/=10;
    }else{
      cost++;
    }
  }
  if(sub>0){
    return INF;
  }else{
    return cost;
  }
}

int main(){
  int64_t N;
  std::cin>>N;
  int64_t best=INF;
  for(int64_t i=1;i*i<=N;i++){
    best=std::min(best,check(i*i,N));
  }
  if(best<INF){
    std::cout<<best<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}