#include <iostream>
#include <algorithm>
#include <stdint.h>

int64_t as[200005];
int64_t bs[200005];

int64_t ds[200005];

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int64_t i=0;i<N;i++){
    std::cin>>bs[i];
  }
  int64_t cost=0;
  for(int64_t i=0;i<N;i++){
    ds[i]=as[i]-bs[i];
    cost+=bs[i];
  }
  std::sort(ds,ds+N);
  for(int64_t i=0;i<N;i++){
    if((ds[i]>=0)&&(i>=K)){
      break;
    }
    cost+=ds[i];
  }
  std::cout<<cost<<std::endl;
  return 0;
}