#include <iostream>

int as[1000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int best=std::min(as[0],as[N-1]);
  for(int i=1;i<N;i++){
    best=std::min(best,std::max(as[i],as[i-1]));
  }
  std::cout<<best<<std::endl;
  return 0;
}