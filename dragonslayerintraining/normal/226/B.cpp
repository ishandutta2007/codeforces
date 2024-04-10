#include <iostream>
#include <algorithm>
#include <stdint.h>

int64_t as[100001];

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<=N;i++){
    std::cin>>as[i];
  }
  std::sort(as+1,as+N+1);
  std::reverse(as+1,as+N+1);
  int64_t one_cost=0;
  for(int64_t i=0;i<N;i++){
    one_cost+=i*(as[i+1]);
  }
  for(int i=1;i<=N;i++){
    as[i]+=as[i-1];
  }
  int Q;
  std::cin>>Q;
  for(int i=0;i<Q;i++){
    int K;
    std::cin>>K;
    int64_t cost=0;
    if(K>1){
      for(int64_t size=1,mult=0;;size*=K,mult++){
	if((size*K-1)/(K-1)>N){
	  cost+=mult*(as[N]-as[(size-1)/(K-1)]);
	  break;
	}
	cost+=mult*(as[(size*K-1)/(K-1)]-as[(size-1)/(K-1)]);
      }
    }else{
      cost=one_cost;
    }
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<cost;
  }
  std::cout<<std::endl;
  return 0;
}