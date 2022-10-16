#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

int64_t N,S;

int64_t big(int64_t num){
  int64_t sum=0;
  for(int64_t num2=num;num2>0;num2/=10){
    sum+=num2%10;
  }
  return num-sum;
}

int main(){
  std::cin>>N>>S;
  int64_t low=0,high=1000000000000000000+1;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(big(mid)<S){
      low=mid;
    }else{
      high=mid;
    }
  }
  std::cout<<std::max<int64_t>(0,N-low)<<std::endl;
  return 0;
}