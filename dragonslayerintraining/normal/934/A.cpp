#include <iostream>
#include <stdint.h>

int64_t as[100],bs[100];

int main(){
  int64_t N,M;
  std::cin>>N>>M;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int64_t i=0;i<M;i++){
    std::cin>>bs[i];
  }
  int64_t opt=1e18;
  for(int64_t i=0;i<N;i++){
    int64_t opt2=-1e18;
    for(int64_t j=0;j<M;j++){
      for(int64_t k=0;k<N;k++){
	if(k==i) continue;
	opt2=std::max(opt2,as[k]*bs[j]);
      }
    }
    opt=std::min(opt,opt2);
  }
  std::cout<<opt<<std::endl;
  return 0;
}