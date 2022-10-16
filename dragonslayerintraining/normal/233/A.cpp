#include <iostream>

int main(){
  int N;
  std::cin>>N;
  if(N%2==1){
    std::cout<<-1<<std::endl;
  }else{
    for(int i=0;i<N/2;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<i*2+2<<" "<<i*2+1;
    }
    std::cout<<std::endl;
  }
  return 0;
}