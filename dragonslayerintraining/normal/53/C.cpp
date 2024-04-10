#include <iostream>

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    if(i%2==0){
      std::cout<<i/2+1;
    }else{
      std::cout<<N-i/2;
    }
  }
  std::cout<<std::endl;
  return 0;
}