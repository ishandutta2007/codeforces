#include <iostream>
#include <iomanip>

int main(){
  int L,D,V,G,R;
  std::cin>>L>>D>>V>>G>>R;
  std::cout<<std::fixed<<std::setprecision(10);
  int t=double(D)/V;
  if(t%(G+R)<G){
    std::cout<<double(L)/V<<std::endl;
  }else{
    t=(t/(G+R)+1)*(G+R);
    std::cout<<t+double(L-D)/V<<std::endl;
  }
  return 0;
}