#include <iostream>
#include <algorithm>
#include <stdint.h>

int64_t as[100000];

int64_t rem=0;

int main(){
  int N,X;
  std::cin>>N>>X;
  X--;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int64_t min=*std::min_element(as,as+N);
  for(int i=0;i<N;i++){
    as[i]-=min;
  }
  rem=min*N;
  for(int i=X;;i=(i+N-1)%N){
    if(as[i]==0){
      as[i]=rem;
      break;
    }else{
      as[i]--;
      rem++;
    }
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<as[i];
  }
  std::cout<<std::endl;
  return 0;
}