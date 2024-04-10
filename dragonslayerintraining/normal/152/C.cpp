#include <iostream>
#include <set>
#include <stdint.h>

int64_t N,M;

std::string grid[100];

int main(){
  std::cin>>N>>M;
  for(int64_t i=0;i<N;i++){
    std::cin>>grid[i];
  }
  int64_t total=1;
  for(int64_t i=0;i<M;i++){
    std::set<int64_t> uniq;
    for(int64_t j=0;j<N;j++){
      uniq.insert(grid[j][i]);
    }
    total*=uniq.size();
    total%=1000000007;
  }
  std::cout<<total<<std::endl;
  return 0;
}