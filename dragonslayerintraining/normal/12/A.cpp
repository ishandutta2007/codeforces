#include <iostream>

int main(){
  std::string keypad[3];
  for(int i=0;i<3;i++){
    std::cin>>keypad[i];
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(keypad[i][j]!=keypad[2-i][2-j]){
	std::cout<<"NO"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}