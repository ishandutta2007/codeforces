#include <iostream>
#include <stdint.h>

int64_t cs[30];
int main(){
  int64_t N,L;
  std::cin>>N>>L;
  for(int64_t i=0;i<N;i++){
    std::cin>>cs[i];
  }
  for(int64_t i=N-1;i>0;i--){
    cs[i-1]=std::min(cs[i-1],cs[i]);
  }
  for(int64_t i=1;i<N;i++){
    cs[i]=std::min(cs[i],cs[i-1]*2);
  }
  int64_t best=1e18;
  for(int64_t X=L;X<=(1LL<<32);X+=(X&-X)){
    L=X;
    int64_t cost=0;
    for(int64_t k=N-1;k>=0;k--){
      if(L>=(1LL<<k)){
	cost+=L/(1LL<<k)*cs[k];
	L%=(1LL<<k);
      }
    }
    best=std::min(best,cost);
  }
  std::cout<<best<<std::endl;
  return 0;
}