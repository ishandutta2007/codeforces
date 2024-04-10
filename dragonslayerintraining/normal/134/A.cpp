#include <iostream>
#include <vector>

int as[200000];
int total=0;
int N;

std::vector<int> good;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
    total+=as[i];
  }
  for(int i=0;i<N;i++){
    if(as[i]*N==total){
      good.push_back(i);
    }
  }
  std::cout<<good.size()<<std::endl;
  for(int i=0;i<good.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<good[i]+1;
  }
  std::cout<<std::endl;
  
  return 0;
}