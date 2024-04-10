#include <iostream>

int main(){
  long long N,X,Y;
  std::cin>>N>>X>>Y;
  if((N<=Y)&&(N-1+(Y-N+1)*(Y-N+1)>=X)){
    std::cout<<(Y-N+1)<<std::endl;
    for(int i=1;i<N;i++){
      std::cout<<1<<std::endl;
    }
  }else{
    std::cout<<-1<<std::endl;
  }
}