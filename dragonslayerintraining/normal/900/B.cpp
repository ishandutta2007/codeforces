#include <iostream>

struct State{
  int num,den;
  State(int num,int den):num(num%den),den(den){
  }
  int next(){
    num*=10;
    int ret=num/den;
    num%=den;
    return ret;
  }
};

bool operator==(struct State s1,struct State s2){
  return (s1.num==s2.num)&&(s1.den=s2.den);
}

int main(){
  int A,B,C;
  std::cin>>A>>B>>C;
  struct State hare(A,B);
  struct State turtle(A,B);
  for(int i=1;;i+=2){
    if(C==hare.next()){
      std::cout<<i<<std::endl;
      return 0;
    }
    if(C==hare.next()){
      std::cout<<i+1<<std::endl;
      return 0;
    }
    turtle.next();
    if(turtle==hare){
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
}