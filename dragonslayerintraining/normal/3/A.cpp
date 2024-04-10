#include <iostream>
#include <algorithm>
#include <cmath>

int main(){
  std::string start,end;
  std::cin>>start>>end;
  int dx=start[0]-end[0];
  int dy=start[1]-end[1];
  std::cout<<std::max(std::abs(dx),std::abs(dy))<<std::endl;
  
  while((dx!=0)||(dy!=0)){
    if(dx<0){std::cout<<"R";dx++;}
    if(dx>0){std::cout<<"L";dx--;}
    if(dy<0){std::cout<<"U";dy++;}
    if(dy>0){std::cout<<"D";dy--;}
    std::cout<<std::endl;
  }
  
  return 0;
}