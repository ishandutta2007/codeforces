#include <iostream>
#include <map>
#include <stdint.h>
int64_t score(int64_t n){
  int64_t s=0;
  while(n%2==0){
    s++;
    n/=2;
  }
  while(n%3==0){
    s--;
    n/=3;
  }
  return s;
}

std::map<int64_t,int64_t> map;

int main(){
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    map[score(A)]=A;
  }
  for(auto pair:map){
    if(pair!=*map.begin()){
      std::cout<<" ";
    }
    std::cout<<pair.second;
  }
  std::cout<<std::endl;
  return 0;
}