#include <iostream>

long long X,Y;

void squareroot(long long N,long long& root,long long& rem){
  root=0;
  for(int k=31;k>=0;k--){
    long long newval=root+(1ll<<k);
    if(newval*newval<=N){
      root=newval;
    }
  }
  rem=N-root*root;
}

std::string getcolor(long long x,long long y){
  if((x==0)||(y==0)){
    return "black";
  }
  long long root,rem;
  squareroot(x*x+y*y,root,rem);
  if(rem==0){
    return "black";
  }
  bool color=(root%2==0);
  if(x<0){
    color=!color;
  }
  if(y<0){
    color=!color;
  }
  return color?"black":"white";
}

int main(){
  std::cin>>X>>Y;
  std::cout<<getcolor(X,Y)<<std::endl;
  return 0;
}