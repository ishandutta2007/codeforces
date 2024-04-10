#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
  long long A,B,C;
  std::cin>>A>>B>>C;
  std::cout<<std::fixed<<std::setprecision(5);
  if(A!=0){
    long long disc=B*B-4*A*C;
    if(disc>0){
      std::cout<<2<<std::endl;
      if(A>0){
	std::cout<<double(-B-sqrt(disc))/2/A<<std::endl;
	std::cout<<double(-B+sqrt(disc))/2/A<<std::endl;
      }else{
	std::cout<<double(-B+sqrt(disc))/2/A<<std::endl;
	std::cout<<double(-B-sqrt(disc))/2/A<<std::endl;
      }
    }else if(disc==0){
      std::cout<<1<<std::endl;
      std::cout<<double(-B)/2/A<<std::endl;
    }else{
      std::cout<<0<<std::endl;
    }
  }else if(B!=0){
    std::cout<<1<<std::endl;
    std::cout<<double(-C)/B<<std::endl;
  }else if(C!=0){
    std::cout<<0<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}