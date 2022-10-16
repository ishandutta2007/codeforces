#include <iostream>
#include <algorithm>

int best[1000];

int main(){
  int N,M,K;
  std::cin>>M>>N>>K;
  for(int i=0;i<N;i++){
    best[i]=1e9;
  }
  for(int i=0;i<M;i++){
    int R,C;
    std::cin>>R>>C;
    R--;
    best[R]=std::min(best[R],C); 
  }
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=best[i];
  }
  std::cout<<std::min(sum,K)<<std::endl;
  return 0;
}