#include <iostream>

bool islucky(int num){
  if(num<0){
    num=-num;
  }else if(num==0){
    return false;
  }
  for(;num>0;num/=10){
    if(num%10==8){
      return true;
    }
  }
  return false;
}

int main(){
  int A;
  std::cin>>A;
  int b;
  for(b=1;!islucky(A+b);b++);
  std::cout<<b<<std::endl;
  return 0;
}