#include <iostream>

void eea(long long A,long long B,long long C,long long& x,long long& y,bool& possible){
  if(B==0){
    if(C%A!=0){
      possible=false;
    }else{
      possible=true;
      x=-C/A;
      y=0;
    }
  }else{
    eea(B,A%B,C,y,x,possible);
    y-=(A/B)*x;
  }
}

int main(){
  long long A,B,C;
  std::cin>>A>>B>>C;
  long long x,y;
  bool possible;
  eea(A,B,C,x,y,possible);
  if(possible){
    std::cout<<x<<" "<<y<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}