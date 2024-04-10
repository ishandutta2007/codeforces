#include <iostream>

int main(){
  int T;
  std::cin>>T;
  for(int i=0;i<T;i++){
    int A;
    std::cin>>A;
    if(360%(180-A)==0){
      std::cout<<"YES"<<std::endl;
    }else{
      std::cout<<"NO"<<std::endl;
    }
  }
  return 0;
}