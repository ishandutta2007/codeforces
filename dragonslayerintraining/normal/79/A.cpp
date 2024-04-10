#include <iostream>

int main(){
  int X,Y;
  std::cin>>X>>Y;
  while(true){
    if((X>=2)&&(Y>=2)){
      X-=2,Y-=2;
    }else if((X>=1)&&(Y>=12)){
      X-=1,Y-=12;
    }else if((X>=0)&&(Y>=22)){
      X-=0,Y-=22;
    }else{
      std::cout<<"Hanako"<<std::endl;
      return 0;
    }
    if((X>=0)&&(Y>=22)){
      X-=0,Y-=22;
    }else if((X>=1)&&(Y>=12)){
      X-=1,Y-=12;
    }else if((X>=2)&&(Y>=2)){
      X-=2,Y-=2;
    }else{
      std::cout<<"Ciel"<<std::endl;
      return 0;
    }
  }
  return 0;
}