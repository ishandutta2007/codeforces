#include <iostream>
#include <map>

std::map<std::pair<int,int>,int> places;
int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    int P,T;
    std::cin>>P>>T;
    places[std::make_pair(-P,T)]++;
  }
  for(std::pair<std::pair<int,int>,int> v:places){
    K-=v.second;
    if(K<=0){
      std::cout<<v.second<<std::endl;
      return 0;
    }
  }
  return 0;
}