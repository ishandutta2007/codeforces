#include <iostream>
#include <algorithm>

struct cdragon{
  int X,Y;
  bool operator<(struct cdragon other)const{
    return X<other.X;
  }
}dragons[10000];

int main(){
  int S,N;
  std::cin>>S>>N;
  for(int i=0;i<N;i++){
    std::cin>>dragons[i].X>>dragons[i].Y;
  }
  std::sort(dragons,dragons+N);
  for(int i=0;i<N;i++){
    if(S<=dragons[i].X){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
    S+=dragons[i].Y;
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}