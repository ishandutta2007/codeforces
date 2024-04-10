#include <iostream>
#include <algorithm>

int M,N;
int cost[100];

int main(){
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>cost[i];
  }
  std::sort(cost,cost+N);
  int earn=0;
  for(int i=0;i<M;i++){
    if(cost[i]>=0){
      break;
    }
    earn-=cost[i];
  }
  std::cout<<earn<<std::endl;
  return 0;
}