#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int cnt=0;
  for(int i=0;i<N;i++){
    int P,Q;
    std::cin>>P>>Q;
    cnt+=((Q-P)>=2);
  }
  std::cout<<cnt<<std::endl;
  return 0;
}