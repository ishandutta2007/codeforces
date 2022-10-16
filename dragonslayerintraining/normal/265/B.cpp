#include <iostream>
#include <cmath>

int main(){
  int N;
  std::cin>>N;
  int loc=0;
  int time=N-1+N;
  for(int i=0;i<N;i++){
    int H;
    std::cin>>H;
    time+=std::abs(H-loc);
    loc=H;
  }
  std::cout<<time<<std::endl;
  return 0;
}