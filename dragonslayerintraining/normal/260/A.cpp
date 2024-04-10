#include <iostream>
#include <sstream>

std::ostringstream out;

int main(){
  int A,B,N;
  std::cin>>A>>B>>N;
  out<<A;
  int rem=A%B;
  for(int i=0;i<N;i++){
    rem=(rem*10)%B;
    int diff=(B-rem)%B;
    if(diff<10){
      out<<diff;
      rem=0;
    }else{
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  std::cout<<out.str()<<std::endl;
  return 0;
}