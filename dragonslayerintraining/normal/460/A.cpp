#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;;i++){
    N-=1;
    if(N<0){
      std::cout<<i-1<<std::endl;
      return 0;
    }
    if(i%M==0){
      N++;
    }
  }
}