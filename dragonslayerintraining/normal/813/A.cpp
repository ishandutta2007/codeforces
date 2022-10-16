#include <iostream>

int sum=0;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    sum+=A;
  }
  int M;
  std::cin>>M;
  for(int i=0;i<M;i++){
    int L,R;
    std::cin>>L>>R;
    if((sum>=L)&&(sum<=R)){
      std::cout<<sum<<std::endl;
      return 0;
    }else if(sum<=L){
      std::cout<<L<<std::endl;
      return 0;
    }
  }
  std::cout<<-1<<std::endl;
  return 0;
}