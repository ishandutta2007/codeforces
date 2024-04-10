#include <iostream>
#include <algorithm>

int as[100000];

int N;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  if(N>1){
    std::cout<<1;
    for(int i=1;i<N-1;i++){
      std::cout<<" "<<as[i-1];
    }
    for(int i=0;;i++){
      if(i==N){
	std::cout<<" "<<2;
	break;
      }
      if(as[i]!=1){
	std::cout<<" "<<as[N-2];
	break;
      }
    }
  }else{
    std::cout<<((as[0]==1)?2:1);
  }
  std::cout<<std::endl;
  return 0;
}