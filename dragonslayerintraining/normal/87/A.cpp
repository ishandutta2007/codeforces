#include <iostream>

int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}

int main(){
  int A,B;
  std::cin>>A>>B;
  int g=gcd(A,B);

  if((A-B==g)||(B-A==g)){
    std::cout<<"Equal"<<std::endl;
  }else if(A>B){
    std::cout<<"Masha"<<std::endl;
  }else{
    std::cout<<"Dasha"<<std::endl;
  }
  
  return 0;
}