#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

struct croad{
  int a,b,c;
}roads[100];

int N;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>roads[i].a>>roads[i].b>>roads[i].c;
  }
  std::vector<int> cycle;
  int costa=0,costb=0;
  cycle.push_back(1);
  while(cycle.size()<N+1){
    for(int j=0;j<N;j++){
      if(roads[j].a==cycle.back()){
	cycle.push_back(roads[j].b);
	costa+=roads[j].c;
      }else if(roads[j].b==cycle.back()){
	cycle.push_back(roads[j].a);
	costb+=roads[j].c;
      }
    }
  }
  std::cout<<std::min(costa,costb)<<std::endl;
  return 0;
}