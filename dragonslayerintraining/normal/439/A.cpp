#include <iostream>

int N,D;

int main(){
  std::cin>>N>>D;
  for(int i=0;i<N;i++){
    int T;
    std::cin>>T;
    D-=T;
  }
  D-=(N-1)*10;
  if(D<0){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<((N-1)*2+D/5)<<std::endl;
  }
  return 0;
}