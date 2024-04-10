#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  while(true){
    for(int i=1;i<=N;i++){
      if(M>=i){
	M-=i;
      }else{
	std::cout<<M<<std::endl;
	return 0;
      }
    }
  }
}