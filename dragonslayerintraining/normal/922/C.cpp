#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  if(K>=43){
    std::cout<<"No"<<std::endl;
  }else{
    do{
      if((N+1)%K!=0){
	std::cout<<"No"<<std::endl;
	return 0;
      }
    }while(K-->1);
    std::cout<<"Yes"<<std::endl;
  }
  return 0;
}