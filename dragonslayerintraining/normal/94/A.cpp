#include <iostream>

int main(){
  std::string code;
  std::string digits[10];
  std::cin>>code;
  for(int i=0;i<10;i++){
    std::cin>>digits[i];
  }
  for(int i=0;i<80;i+=10){
    for(int k=0;k<10;k++){
      if(code.compare(i,10,digits[k])==0){
	std::cout<<k;
      }
    }
  }
  std::cout<<std::endl;
  return 0;
}