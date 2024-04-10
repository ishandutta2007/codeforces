#include <iostream>

int as[7];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<7;i++){
    std::cin>>as[i];
  }
  for(;;){
    for(int i=0;i<7;i++){
      N-=as[i];
      if(N<=0){
	std::cout<<(i+1)<<std::endl;
	return 0;
      }
    }
  }
  return 0;
}