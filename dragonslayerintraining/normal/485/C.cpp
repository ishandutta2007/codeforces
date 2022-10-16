#include <iostream>
#include <stdint.h>

int main(){
  int64_t N;
  std::cin>>N;
  while(N-->0){
    int64_t L,R;
    std::cin>>L>>R;
    int64_t k;
    for(k=60;k>=0;k--){
      if(((L>>k)&1)!=((R>>k)&1)){
	break;
      }
    }
    if(k<0){
      std::cout<<L<<std::endl;
      continue;
    }
    //kth bit differs
    int64_t ones=((1LL<<k)-1);
    if((R&ones)==ones){
      std::cout<<R<<std::endl;
    }else{
      std::cout<<(L|ones)<<std::endl;
    }
  }
  return 0;
}