#include <iostream>

int main(){
  int A,B,C,D,E,F;
  std::cin>>A>>B>>C>>D>>E>>F;
  if(A*C*E<B*D*F){
    std::cout<<"Ron"<<std::endl;
  }else if((C==0)&&(D>0)){
    std::cout<<"Ron"<<std::endl;
  }else if((A==0)&&(B>0)&&(D>0)){
    std::cout<<"Ron"<<std::endl;
  }else{
    std::cout<<"Hermione"<<std::endl;
  }
  return 0;
}