#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int x=0,y=0,z=0;
  for(int i=0;i<N;i++){
    int dx,dy,dz;
    std::cin>>dx>>dy>>dz;
    x+=dx,y+=dy,z+=dz;
  }
  std::cout<<(((x==0)&&(y==0)&&(z==0))?"YES":"NO")<<std::endl;
  return 0;
}