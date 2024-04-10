#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
  int x[2],y[2],r[2];
  for(int i=0;i<2;i++){
    std::cin>>x[i]>>y[i]>>r[i];
  }
  int dx=x[0]-x[1],dy=y[0]-y[1];
  double dist=sqrt(dx*dx+dy*dy);
  double best;
  if(dist+r[0]<r[1]){
    best=r[1]-r[0]-dist;
  }else if(dist+r[1]<r[0]){
    best=r[0]-r[1]-dist;
  }else if(r[0]+r[1]<dist){
    best=dist-r[0]-r[1];
  }else{
    best=0;
  }
  std::cout<<std::fixed<<std::setprecision(10)<<best/2<<std::endl;
  return 0;
}