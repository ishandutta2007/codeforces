#include <iostream>
#include <stdint.h>

int64_t MOD=1e9+7;

int64_t ways[5001]={1};

int main(){
  int N;
  std::cin>>N;
  while(N-->0){
    std::string command;
    std::cin>>command;
    if(command=="f"){
      for(int i=5000;i>0;i--){
	ways[i]=ways[i-1];
      }
      ways[0]=0;
    }else{
      for(int i=5000-1;i>=0;i--){
	ways[i]=(ways[i]+ways[i+1])%MOD;
      }
    }
  }
  std::cout<<ways[0]<<std::endl;
  return 0;
}