#include <iostream>
#include <stdint.h>

int64_t isqrt(int64_t num){
  int64_t low=1,high=1e9;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(mid*mid<=num){
      low=mid;
    }else{
      high=mid;
    }
  }
  return low;
}

int main(){
  int64_t X,Y,Z;
  std::cin>>X>>Y>>Z;
  int64_t A=isqrt(X*Y*Z);
  std::cout<<(A/X+A/Y+A/Z)*4<<std::endl;
  return 0;
}