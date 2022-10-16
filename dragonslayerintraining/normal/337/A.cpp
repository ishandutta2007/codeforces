#include <iostream>
#include <algorithm>

int jigsaw[1000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    std::cin>>jigsaw[i];
  }
  std::sort(jigsaw,jigsaw+M);
  int best=1e9;
  for(int i=0;i<=M-N;i++){
    best=std::min(best,jigsaw[i+N-1]-jigsaw[i]);
  }
  std::cout<<best<<std::endl;
  return 0;
}