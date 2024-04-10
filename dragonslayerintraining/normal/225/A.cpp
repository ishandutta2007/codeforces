#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int X;
  std::cin>>X;
  for(int i=0;i<N;i++){
    X=7-X;
    int A,B;
    std::cin>>A>>B;
    if(A>3){
      A=7-A;
    }
    if(B>3){
      B=7-B;
    }
    int C=A^B;
    if((X!=C)&&(X+C!=7)){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}