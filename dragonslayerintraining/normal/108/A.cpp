#include <iostream>
#include <iomanip>
#include <cstdio>

#define rev(X) ((X)%10*10+(X)/10)

int main(){
  int H,M;
  for(scanf("%d:%d",&H,&M);;H=(H+1)%24,M=-1){
    if((rev(H)>M)&&(rev(H)<60)){
      std::cout<<std::setfill('0')<<std::setw(2)<<H<<":"<<std::setfill('0')<<std::setw(2)<<rev(H)<<std::endl;
      return 0;
    }
  }
}