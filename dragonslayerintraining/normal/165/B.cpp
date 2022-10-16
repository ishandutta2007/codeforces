#include <iostream>
#include <stdint.h>

int64_t test(int64_t num,int64_t K){
  int64_t sum=0;
  while(num>0){
    sum+=num,num/=K;
  }
  return sum;
}

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  
  int64_t low=0,high=1e10;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(test(mid,K)>=N){
      high=mid;
    }else{
      low=mid;
    }
  }
  std::cout<<high<<std::endl;
  return 0;
}