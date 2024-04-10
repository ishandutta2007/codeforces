#include <iostream>

int good[2],bad[2];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int T,X,Y;
    std::cin>>T>>X>>Y;
    good[T-1]+=X;
    bad[T-1]+=Y;
  }
  for(int i=0;i<2;i++){
    std::cout<<((good[i]>=bad[i])?"LIVE":"DEAD")<<std::endl;
  }
  return 0;
}