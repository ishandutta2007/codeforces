#include <iostream>
#include <queue>
#include <stdint.h>
#include <cmath>

int64_t as[1000],bs[1000],ds[1000];

int main(){
  int64_t N,K1,K2;
  std::cin>>N>>K1>>K2;
  int64_t K=K1+K2;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int64_t i=0;i<N;i++){
    std::cin>>bs[i];
  }
  std::priority_queue<int64_t> next;
  int64_t cost=0;
  for(int64_t i=0;i<N;i++){
    ds[i]=std::abs(as[i]-bs[i]);
    cost+=ds[i]*ds[i];
    if(ds[i]>0){
      next.push(2*ds[i]-1);
    }
  }
  for(int64_t i=0;i<K;i++){
    if(next.empty()){
      cost++;
      next.push(1);
    }else{
      int64_t val=next.top();
      next.pop();
      cost-=val;
      if(val>1){
	next.push(val-2);
      }
    }
  }
  std::cout<<cost<<std::endl;
  return 0;
}