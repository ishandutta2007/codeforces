#include <iostream>

int as[2000];

int main(){
  int N,M;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int parity=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      if(as[j]>as[i]){
	parity^=1;
      }
    }
  }
  std::cin>>M;
  for(int i=0;i<M;i++){
    int L,R;
    std::cin>>L>>R;
    switch((R-L)%4){
    case 1:
    case 2:
      parity^=1;
      break;
    default:
      break;
    }
    if(parity){
      std::cout<<"odd"<<std::endl;
    }else{
      std::cout<<"even"<<std::endl;
    }
  }
  return 0;
}