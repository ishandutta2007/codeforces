#include <iostream>
#include <vector>

std::vector<int> v;

int main(){
  int Y,K,N;
  std::cin>>Y>>K>>N;
  for(int i=(Y/K+1)*K;i<=N;i+=K){
    if(i>Y){
      v.push_back(i-Y);
    }
  }
  if(v.size()==0){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(int i=0;i<v.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<v[i];
  }
  std::cout<<std::endl;
  return 0;
}