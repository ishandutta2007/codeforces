#include <iostream>

int main(){
  int A1,B1,C1,A2,B2,C2;
  std::cin>>A1>>B1>>C1>>A2>>B2>>C2;
  if(((A1==0)&&(B1==0)&&(C1!=0))||
     ((A2==0)&&(B2==0)&&(C2!=0))){
    std::cout<<0<<std::endl;
  }else if(A1*B2==A2*B1){
    if((A1*C2==A2*C1)&&(B1*C2==B2*C1)){
      std::cout<<-1<<std::endl;
    }else{
      std::cout<<0<<std::endl;
    }
  }else{
    std::cout<<1<<std::endl;
  }
  return 0;
}