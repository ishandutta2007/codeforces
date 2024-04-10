#include <iostream>
#include <algorithm>

int as[100001]={1};

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<=N;i++){
    std::cin>>as[i];
    as[i]+=as[i-1];
  }
  int M;
  std::cin>>M;
  for(int i=0;i<M;i++){
    int Q;
    std::cin>>Q;
    std::cout<<std::upper_bound(as,as+N+1,Q)-as<<std::endl;
  }
  return 0;
}