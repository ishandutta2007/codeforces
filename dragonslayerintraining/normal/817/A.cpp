#include <iostream>
#include <cmath>
#include <stdint.h>

int main(){
  int64_t DX,DY;
  {
    int64_t X1,Y1,X2,Y2;
    std::cin>>X1>>Y1>>X2>>Y2;
    DX=std::abs(X2-X1);
    DY=std::abs(Y2-Y1);
  }
  int64_t X,Y;
  std::cin>>X>>Y;
  if((DX%X==0)&&(DY%Y==0)){
    DX/=X;
    DY/=Y;
    if((DX+DY)%2==0){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}