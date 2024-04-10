#include <iostream>

int main(){
  int N;
  std::cin>>N;
  std::cout<<N;
  for(int i=2;N>1;i++){
    while(N%i==0){
      N/=i;
      std::cout<<" "<<N;
    }
  }
  std::cout<<std::endl;
  return 0;
}