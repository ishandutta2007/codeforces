#include <iostream>

int main(){
  int N,A,B;
  std::cin>>N>>A>>B;
  A--,B--;
  int round=0;
  while(A!=B){
    A/=2,B/=2,N/=2;
    round++;
  }
  if(N==1){
    std::cout<<"Final!"<<std::endl;
  }else{
    std::cout<<round<<std::endl;
  }
  return 0;
}