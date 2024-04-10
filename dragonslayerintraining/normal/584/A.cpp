#include <iostream>

int cntdigits(int num){
  int cnt=0;
  for(;num>0;num/=10){
    cnt++;
  }
  return cnt;
}

int main(){
  int N,T;
  std::cin>>N>>T;
  int D=cntdigits(T);
  if(N<D){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<T;
    for(int i=D;i<N;i++){
      std::cout<<0;
    }
    std::cout<<std::endl;
  }
  return 0;
}