#include <iostream>
#include <vector>

int zeros,hundred,both,tens,ones;

int main(){
  int K;
  std::cin>>K;
  for(int i=0;i<K;i++){
    int D;
    std::cin>>D;
    if(D==0){
      zeros++;
    }else if(D==100){
      hundred=1;
    }else if(D%10==0){
      tens=both=D;
    }else if(D/10==0){
      ones=both=D;
    }else{
      both=D;
    }
  }
  if(tens&&ones){
    std::cout<<zeros+hundred+2<<std::endl;
    std::cout<<tens<<std::endl;
    std::cout<<ones<<std::endl;
  }else if(both){
    std::cout<<zeros+hundred+1<<std::endl;
    std::cout<<both<<std::endl;
  }else{
    std::cout<<zeros+hundred<<std::endl;
  }
  while(zeros-->0){
    std::cout<<0<<std::endl;
  }
  if(hundred){
    std::cout<<100<<std::endl;
  }
  return 0;
}