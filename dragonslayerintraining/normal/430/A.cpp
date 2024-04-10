#include <iostream>
#include <algorithm>

int bs[100];
std::pair<int,int> xs[100];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>xs[i].first;
    xs[i].second=i;
  }
  std::sort(xs,xs+N);
  for(int i=0;i<N;i++){
    bs[xs[i].second]=i%2;
  }
  for(int i=0;i<N;i++){
    if(i>0) std::cout<<" ";
    std::cout<<bs[i];
  }
  std::cout<<std::endl;
  return 0;
}