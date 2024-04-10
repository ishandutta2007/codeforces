#include <iostream>

int main(){
  long long N;
  std::cin>>N;
  if(N%2==0){
    std::cout<<N/2<<std::endl;
  }else{
    std::cout<<N/2-N<<std::endl;
  }
  return 0;
}