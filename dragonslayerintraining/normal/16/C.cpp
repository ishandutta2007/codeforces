#include <iostream>

long long gcd(long long a,long long b){
  return (b==0)?a:gcd(b,a%b);
}

int main(){
  long long A,B,X,Y;
  std::cin>>A>>B>>X>>Y;
  int g=gcd(X,Y);
  X/=g,Y/=g;
  long long s=std::min(A/X,B/Y);
  std::cout<<s*X<<" "<<s*Y<<std::endl;
  return 0;
}