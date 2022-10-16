#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int x=1000,y=1000;
  while(true){
    if((x-1)*y>=N){
      x--;
    }else{
      break;
    }
    if(x*(y-1)>=N){
      y--;
    }else{
      break;
    }
  }
  std::cout<<2*(x+y)<<std::endl;
  return 0;
}