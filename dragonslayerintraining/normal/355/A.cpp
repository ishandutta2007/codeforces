#include <iostream>

int K,D;

int main(){
  std::cin>>K>>D;
  if(D==0){
    if(K==1){
      std::cout<<0<<std::endl;
    }else{
      std::cout<<"No solution"<<std::endl;
    }
  }else{
    std::cout<<D;
    for(int i=1;i<K;i++){
      std::cout<<"0";
    }
    std::cout<<std::endl;
  }
  return 0;
}