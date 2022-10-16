#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> good[3];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int T;
    std::cin>>T;
    T--;
    good[T].push_back(i+1);
  }
  unsigned int best=1e9;
  for(int i=0;i<3;i++){
    best=std::min<unsigned int>(best,good[i].size());
  }
  std::cout<<best<<std::endl;
  for(int i=0;i<best;i++){
    std::cout<<good[0][i]<<" "<<good[1][i]<<" "<<good[2][i]<<std::endl;
  }
  return 0;
}