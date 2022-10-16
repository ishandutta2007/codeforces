#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int door[2]={0,0};
  for(int i=0;i<N;i++){
    for(int k=0;k<2;k++){
      int D;
      std::cin>>D;
      door[k]+=D;
    }
  }
  int res=0;
  for(int k=0;k<2;k++){
    res+=std::min(door[k],N-door[k]);
  }
  std::cout<<res<<std::endl;
  return 0;
}