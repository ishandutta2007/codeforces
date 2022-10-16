#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      std::string c;
      std::cin>>c;
      if((c!="B")&&(c!="G")&&(c!="W")){
	std::cout<<"#Color"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"#Black&White"<<std::endl;
  return 0;
}