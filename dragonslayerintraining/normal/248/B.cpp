#include <iostream>
#include <iomanip>

int main(){
  int N;
  std::cin>>N;
  if(N<3){
    std::cout<<-1<<std::endl;
    return 0;
  }else if(N==3){
    std::cout<<210<<std::endl;
    return 0;
  }
  int pow=1;
  for(int i=0;i<N-1;i++){
    pow=(pow*10)%210;
  }
  for(int i=0;i<N-3;i++){
    if(i==0){
      std::cout<<"1";
    }else{
      std::cout<<"0";
    }
  }
  std::cout<<std::setw(3)<<std::setfill('0')<<(210-pow)%210<<std::endl;
}