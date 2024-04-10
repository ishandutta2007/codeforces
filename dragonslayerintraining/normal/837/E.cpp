#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

int64_t X,Y;

std::vector<int64_t> factors;

void factorize(){
  int64_t num=X;
  for(int64_t i=2;i*i<=X;i++){
    while(num%i==0){
      factors.push_back(i);
      num/=i;
    }
  }
  if(num>1){
    factors.push_back(num);
  }
}

int main(){
  std::cin>>X>>Y;
  factorize();
  int64_t res=0;
  while(Y>0){
    for(int64_t& prime:factors){
      if(Y%prime==0){
	Y/=prime;
	prime=1;
      }
    }
    factors.erase(std::remove(factors.begin(),factors.end(),1),factors.end());
    int64_t next=0;
    for(int64_t prime:factors){
      next=std::max(next,Y/prime*prime);
    }
    res+=Y-next;
    Y=next;
  }
  std::cout<<res<<std::endl;
  return 0;
}