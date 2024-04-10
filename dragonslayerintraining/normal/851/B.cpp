#include <iostream>
#include <stdint.h>

int64_t xs[3],ys[3];

int main(){
  for(int i=0;i<3;i++){
    std::cin>>xs[i]>>ys[i];
  }
  xs[0]-=xs[1],ys[0]-=ys[1];
  xs[2]-=xs[1],ys[2]-=ys[1];
  std::cerr<<xs[0]<<","<<ys[0]<<":"<<xs[2]<<","<<ys[2]<<std::endl;
  if((xs[0]*xs[0]+ys[0]*ys[0]==xs[2]*xs[2]+ys[2]*ys[2])&&
     (xs[0]*ys[2]!=xs[2]*ys[0])){
    std::cout<<"Yes"<<std::endl;
  }else{
    std::cout<<"No"<<std::endl;
  }
  return 0;
}