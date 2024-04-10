#include <iostream>
#include <stdint.h>

int main(){
  int64_t P,D;
  std::cin>>P>>D;
  int64_t best=P;
  for(int64_t tens=10;tens<=P;tens*=10){
    if((P+1)%tens<=D){
      best=(P+1)/tens*tens-1;
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}