#include <iostream>

int as[100000];
std::string bs;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::cin>>bs;
  int R=1e9;
  int L=-1e9;
  for(int i=4;i<N;i++){
    if((bs[i]=='0')&&(bs[i-1]=='1')){
      for(int k=0;k<5;k++){
	R=std::min(R,as[i-k]-1);
      }
    }else if((bs[i]=='1')&&(bs[i-1]=='0')){
      for(int k=0;k<5;k++){
	L=std::max(L,as[i-k]+1);
      }
    }
  }
  std::cout<<L<<" "<<R<<std::endl;
  return 0;
}