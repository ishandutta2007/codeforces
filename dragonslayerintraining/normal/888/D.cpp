#include <iostream>
#include <stdint.h>

int64_t ds[5]={1,0,1,2,9};

int64_t combo(int64_t n,int64_t k){
  int64_t ac=1;
  for(int64_t i=0;i<k;i++){
    ac=ac*(n-i)/(i+1);
  }
  return ac;
}

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  int64_t sum=0;
  for(int64_t k=0;k<=K;k++){
    sum+=ds[k]*combo(N,k);
  }
  std::cout<<sum<<std::endl;
  return 0;
}