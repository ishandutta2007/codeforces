#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int current=0;
  int ngroups=0;
  for(int i=0;i<N;i++){
    int magnet;
    std::cin>>magnet;
    if(current!=magnet){
      ngroups++;
      current=magnet;
    }
  }
  std::cout<<ngroups<<std::endl;
  return 0;
}