#include <iostream>

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    if(str.length()>10){
      std::cout<<str[0]<<str.length()-2<<str[str.length()-1]
	       <<std::endl;
    }else{
      std::cout<<str<<std::endl;
    }
  }
  return 0;
}