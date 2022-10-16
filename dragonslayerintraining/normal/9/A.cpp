#include <iostream>
#include <algorithm>

int main(){
  int A,B;
  std::cin>>A>>B;
  int num,den=6;
  num=7-std::max(A,B);

  if(num%2==0){
    num/=2,den/=2;
  }
  if(num%3==0){
    num/=3,den/=3;
  }
  std::cout<<num<<"/"<<den<<std::endl;
  
  return 0;
}