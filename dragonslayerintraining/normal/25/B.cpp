#include <iostream>

int main(){
  int N;
  std::cin>>N;
  std::string str;
  std::cin>>str;
  if(N%2==0){
    for(int i=0;i<N;i++){
      if((i>0)&&(i%2==0)){
	std::cout<<"-";
      }
      std::cout<<str[i];
    }
    std::cout<<std::endl;
  }else{
    for(int i=0;i<N;i++){
      if((i>1)&&(i%2==1)){
	std::cout<<"-";
      }
      std::cout<<str[i];
    }
    std::cout<<std::endl;
  }
  return 0;
}