#include <iostream>
#include <vector>

int C1,C2,C3,C4;
std::vector<int> as,bs;

int solve(const std::vector<int>& vs){
  int cost=0;
  for(int v:vs){
    cost+=std::min(C2,C1*v);
  }
  return std::min(C3,cost);
}

int main(){
  std::cin>>C1>>C2>>C3>>C4;
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    as.push_back(A);
  }
  for(int i=0;i<M;i++){
    int B;
    std::cin>>B;
    bs.push_back(B);
  }
  std::cout<<std::min(C4,solve(as)+solve(bs))<<std::endl;
  return 0;
}