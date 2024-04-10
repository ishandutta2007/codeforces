#include <iostream>

int main(){
  int color[3];
  for(int i=0;i<3;i++){
    std::cin>>color[i];
  }
  std::cout<<std::max((color[0]+1)/2*3-3,
		      std::max((color[1]+1)/2*3-2,
			       (color[2]+1)/2*3-1))+30<<std::endl;
  
  return 0;
}