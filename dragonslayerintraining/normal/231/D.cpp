#include <iostream>

int main(){
  int x,y,z,x0,y0,z0,a[6];
  std::cin>>x>>y>>z>>x0>>y0>>z0;
  for(int i=0;i<6;i++){
    std::cin>>a[i];
  }
  int sum=0;
  if(y<0){
    sum+=a[0];
  }
  if(y>y0){
    sum+=a[1];
  }
  if(z<0){
    sum+=a[2];
  }
  if(z>z0){
    sum+=a[3];
  }
  if(x<0){
    sum+=a[4];
  }
  if(x>x0){
    sum+=a[5];
  }
  std::cout<<sum<<std::endl;
  return 0;
}