#include <iostream>

int main(){
  int V1,V2,T,D;
  std::cin>>V1>>V2>>T>>D;
  int len=0;
  for(int i=0;i<T;i++){
    len+=std::min(V1+i*D,V2+(T-i-1)*D);
  }
  std::cout<<len<<std::endl;
  return 0;
}