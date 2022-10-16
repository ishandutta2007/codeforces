#include <iostream>
#include <stdint.h>

int main(){
  int N;
  int64_t left=1e9,right=-1e9;
  int64_t bottom=1e9,top=-1e9;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int64_t X,Y;
    std::cin>>X>>Y;
    left=std::min(left,X);
    right=std::max(right,X);
    bottom=std::min(bottom,Y);
    top=std::max(top,Y);
  }
  int64_t size=std::max(right-left,top-bottom);
  std::cout<<size*size<<std::endl;
  return 0;
}