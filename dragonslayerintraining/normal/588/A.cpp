#include <iostream>

int N;
int as[100000];
int ps[100000];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i]>>ps[i];
  }
  int cost=0;
  int cheap=1e9;
  for(int i=0;i<N;i++){
    cheap=std::min(cheap,ps[i]);
    cost+=as[i]*cheap;
  }
  std::cout<<cost<<std::endl;
  return 0;
}