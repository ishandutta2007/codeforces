#include <iostream>
#include <algorithm>

int as[3005];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::cout<<N<<std::endl;
  for(int i=0;i<N;i++){
    int* best=std::min_element(as+i,as+N);
    std::cout<<i<<" "<<(best-as)<<std::endl;
    std::swap(as[i],*best);
  }
}