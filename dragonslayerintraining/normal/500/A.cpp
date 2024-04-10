#include <iostream>

int N,T;

int as[30000];

int main(){
  std::cin>>N>>T;
  T--;
  for(int i=0;i<N-1;i++){
    std::cin>>as[i];
  }
  for(int i=0;;i+=as[i]){
    if(i==T){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
    if(i>=N-1){
      break;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}