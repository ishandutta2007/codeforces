#include <iostream>

int main(){
  int N,K;
  std::cin>>N>>K;
  int time_left=240-K;
  int i;
  for(i=1;;i++){
    time_left-=i*5;
    if(time_left<0){
      i--;
      break;
    }
    if(i>N){
      i--;
      break;
    }
  }
  std::cout<<i<<std::endl;
  return 0;
}