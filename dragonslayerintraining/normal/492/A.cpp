#include <iostream>
#include <stdint.h>

int64_t test(int64_t H){
  return H*(H+1)*(H+2)/6;
}

int main(){
  int N;
  std::cin>>N;
  int low=1,high=1e2;
  while(high-low>1){
    int mid=(low+high)/2;
    if(test(mid)<=N){
      low=mid;
    }else{
      high=mid;
    }
  }
  std::cout<<low<<std::endl;
}