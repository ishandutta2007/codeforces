#include <iostream>
#include <algorithm>

int N,L;

int as[1000];

int main(){
  std::cin>>N>>L;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  int D=2*std::max(as[0],L-as[N-1]);
  for(int i=1;i<N;i++){
    D=std::max(D,as[i]-as[i-1]);
  }
  std::cout<<D/2<<"."<<((D%2)?5:0)<<std::endl;
  return 0;
}