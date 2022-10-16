#include <iostream>
#include <map>
#include <cassert>
#include <stdint.h>

int64_t N;
int64_t M;
std::map<int64_t,int64_t> map;

int64_t as[100000];

int64_t halves=0;


int main(){
  std::cin>>N;
  int64_t total=1;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    as[i]=A;
    map[A]++;
  }
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    if(as[i]==A){
      halves++;
    }
    map[A]++;
  }
  std::cin>>M;
  for(std::pair<int64_t,int64_t> pair:map){
    for(int64_t i=1;i<=pair.second;i++){
      int64_t k;
      for(k=i;(k%2==0)&&(halves>0);k/=2,halves--);
      total=(total*k)%M;
    }
  }
  assert(halves==0);
  std::cout<<total<<std::endl;
  return 0;
}