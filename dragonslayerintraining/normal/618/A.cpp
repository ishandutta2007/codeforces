#include <iostream>
#include <vector>

std::vector<int> slimes;

int main(){
  int N;
  std::cin>>N;
  for(int k=30;k>=0;k--){
    if(N&(1<<k)){
      slimes.push_back(k);
    }
  }
  for(int i=0;i<slimes.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<slimes[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}