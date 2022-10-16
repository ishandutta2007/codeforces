#include <iostream>
#include <stdint.h>

struct Point{
  int64_t x,y;
}P[3];

int main(){
  for(int i=0;i<3;i++){
    std::cin>>P[i].x>>P[i].y;
  }
  P[0].x-=P[1].x,P[0].y-=P[1].y;
  P[2].x-=P[1].x,P[2].y-=P[1].y;
  int64_t cross=P[0].x*P[2].y-P[2].x*P[0].y;
  if(cross>0){
    std::cout<<"RIGHT"<<std::endl;
  }else if(cross<0){
    std::cout<<"LEFT"<<std::endl;
  }else{
    std::cout<<"TOWARDS"<<std::endl;
  }
  return 0;
}