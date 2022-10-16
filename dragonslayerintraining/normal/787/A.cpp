#include <iostream>

//overkill

void eea(int a,int b,int c,int& x,int& y,bool& solved){
  if(b==0){
    if(c%a==0){
      solved=true;
      x=c/a,y=0;
    }else{
      solved=false;
    }
  }else{
    eea(b,a%b,c,y,x,solved);
    y-=(a/b)*x;
  }
}

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int A,B,C,D;
  std::cin>>A>>B>>C>>D;
  int lcm=A/gcd(A,C)*C;
  bool solved;
  int x,y;
  eea(A,-C,D-B,x,y,solved);
  if(!solved){
    std::cout<<-1<<std::endl;
    return 0;
  }
  int time=x*A+B;
  if(time<0){
    time=-((-time)%lcm);
  }else{
    time%=lcm;
  }
  if(time<B){
    time+=(B-time+lcm-1)/lcm*lcm;
  }
  if(time<D){
    time+=(D-time+lcm-1)/lcm*lcm;
  }
  std::cout<<time<<std::endl;
  return 0;
}