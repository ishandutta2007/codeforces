#include <iostream>
#include <algorithm>

int hassocks[1000];
int main(){
  int N;
  std::cin>>N;
  int fly=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<=N;j++){
      fly=(fly+j)%N;
      hassocks[fly]=1;
    }
  }
  if(*std::min_element(hassocks,hassocks+N)==1){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}