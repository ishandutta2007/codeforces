#include <iostream>

int as[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int B;
      std::cin>>B;
      if(i!=j){
	as[i]|=B;
	as[j]|=B;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<as[i];
  }
  std::cout<<std::endl;
  return 0;
}