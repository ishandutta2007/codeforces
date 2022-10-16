#include <iostream>

long long sumdigits(long long A,long long base){
  long long sum=0;
  for(;A>0;A/=base){
    sum+=A%base;
  }
  return sum;
}

long long gcd(long long a,long long b){
  return (b==0)?a:gcd(b,a%b);
}

int main(){
  int A;
  std::cin>>A;
  long long sum=0;
  for(int i=2;i<A;i++){
    sum+=sumdigits(A,i);
  }
  long long cnt=A-2;
  long long g=gcd(sum,cnt);
  std::cout<<sum/g<<"/"<<cnt/g<<std::endl;
  return 0;
}