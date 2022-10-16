#include <iostream>
#include <stdint.h>

int64_t N,L,R,Ql,Qr;

int64_t ws[100001];
int64_t cost=0;

int main(){
  std::cin>>N>>L>>R>>Ql>>Qr;
  for(int64_t i=0;i<N;i++){
    std::cin>>ws[i];
    cost+=ws[i]*R;
  }
  int64_t best=1e10;
  for(int64_t i=0;i<=N;i++){
    best=std::min(best,cost+std::max<int64_t>(0,std::max(Ql*(i-(N-i)-1),Qr*((N-i)-i-1))));
    cost+=(L-R)*ws[i];
  }
  std::cout<<best<<std::endl;
  return 0;
}