#include <iostream>
#include <stdint.h>

int64_t N;

int64_t notprime[1000001]={1,1};

bool isqrt(int64_t num,int64_t& root){
  int64_t low=1,high=10000001;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(mid*mid<num){
      low=mid;
    }else if(mid*mid>num){
      high=mid;
    }else{
      root=mid;
      return true;
    }
  }
  return false;
}

int main(){
  std::cin>>N;
  for(int64_t i=2;i<=1000000;i++){
    if(!notprime[i]){ 
      for(int64_t k=i*2;k<=1000000;k+=i){
	notprime[k]=1;
      }
    }
  }
  for(int64_t i=0;i<N;i++){
    int64_t X;
    std::cin>>X;
    int64_t root;
    if(isqrt(X,root)){
      if(notprime[root]){
	std::cout<<"NO"<<std::endl;
      }else{
	std::cout<<"YES"<<std::endl;
      }
    }else{
      std::cout<<"NO"<<std::endl;
    }
  }
  return 0;
}