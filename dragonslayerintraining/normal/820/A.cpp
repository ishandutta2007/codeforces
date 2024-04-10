#include <iostream>

int main(){
  int C,V0,V1,A,L;
  std::cin>>C>>V0>>V1>>A>>L;
  int read=0;
  for(int day=1;;day++){
    int speed=std::min(V0+A*(day-1),V1);
    read+=speed;
    if(day>1){
      read-=L;
    }
    if(read>=C){
      std::cout<<day<<std::endl;
      return 0;
    }
  }
  return 0;
}