#include <iostream>

int N;

void test(int N,int M,int& cost){
  if(M==0){
    cost=1e9;
    return;
  }
  if(M==1){
    cost+=N-1;
    return;
  }
  cost+=N/M;
  N%=M;
  test(M,N,cost);
}

int main(){
  std::cin>>N;
  int best=1e9;
  for(int M=1;M<=N;M++){
    int cost=0;
    test(N,M,cost);
    best=std::min(best,cost);
  }
  std::cout<<best<<std::endl;
  return 0;
}