#include <iostream>

int main(){
  int K,R;
  std::cin>>K>>R;
  for(int i=1;;i++){
    if((i*K%10==R)||(i*K%10==0)){
      std::cout<<i<<std::endl;
      return 0;
    }
  }
}