#include <iostream>

int main(){
  int N,K;
  std::cin>>N>>K;
  int cnt=0;
  for(int i=0;i<N;i++){
    int Y;
    std::cin>>Y;
    cnt+=((5-Y)>=K);
  }
  std::cout<<cnt/3<<std::endl;
  return 0;
}