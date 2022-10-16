#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int a=2*N,b=-N;
  int shift=a/7;
  a-=shift*7;
  b+=shift*4;
  if(b<0){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<std::string(a,'4')<<std::string(b,'7')<<std::endl;
  }
  return 0;
}