#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int min=1e9;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    min=std::min(min,A);
  }
  if(min==1){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<1<<std::endl;
  }
  return 0;
}