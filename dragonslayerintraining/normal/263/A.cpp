#include <iostream>
#include <cmath>

int main(){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      int a;
      std::cin>>a;
      if(a){
	std::cout<<std::abs(i-2)+std::abs(j-2)<<std::endl;
	return 0;
      }
    }
  }
  return 0;
}