#include <iostream>

int main(){
  int N;
  std::cin>>N;
  if(N>=0){
    std::cout<<N<<std::endl;
  }else{
    std::cout<<std::max(-(-N/10),-((-N)/100*10+(-N)%10))<<std::endl;
  }
  return 0;
}