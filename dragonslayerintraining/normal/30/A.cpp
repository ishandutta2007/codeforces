#include <iostream>
#include <cmath>

int power(int a,int b){
  int prod=1;
  while(b>0){
    prod*=a;
    b--;
  }
  return prod;
}

int main(){
  int A,B,N;
  std::cin>>A>>B>>N;
  for(int i=-1000;i<=1000;i++){
    int p=1;
    for(int j=0;j<N;j++){
      p*=i;
      if(std::abs(A*p)>std::abs(B)){
	break;
      }
    }
    if(A*p==B){
      std::cout<<i<<std::endl;
      return 0;
    }
  }
  std::cout<<"No solution"<<std::endl;
  return 0;
}