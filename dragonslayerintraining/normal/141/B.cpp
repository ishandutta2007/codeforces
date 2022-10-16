#include <iostream>

int main(){
  int A,X,Y;
  std::cin>>A>>X>>Y;
  if(Y%A==0){
    std::cout<<-1<<std::endl;
    return 0;
  }
  int level=Y/A;
  if(level==0){
    if((X*2>=A)||(X*2<=-A)){
      std::cout<<-1<<std::endl;
      return 0;
    }else{
      std::cout<<1<<std::endl;
      return 0;
    }
  }
  if(level%2==1){
    if((X*2>=A)||(X*2<=-A)){
      std::cout<<-1<<std::endl;
      return 0;
    }else{
      std::cout<<(level/2*3+2)<<std::endl;
      return 0;
    }
  }else{
    if((X>0)&&(X<A)){
      std::cout<<(level/2*3+1)<<std::endl;
      return 0;
    }else if((X<0)&&(X>-A)){
      std::cout<<(level/2*3)<<std::endl;
      return 0;
    }else{
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  return 0;
}