#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      switch(i%4){
      case 0:case 2:
	std::cout<<"#";
	break;
      case 1:
	std::cout<<((j==M-1)?"#":".");
	break;
      case 3:
	std::cout<<((j==0)?"#":".");
	break;
      }
    }
    std::cout<<std::endl;
  }
  return 0;
}