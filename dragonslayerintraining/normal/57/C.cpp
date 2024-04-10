#include <iostream>

const long long PRIME=1000000007;

void eea(long long a,long long b,long long& x,long long& y,long long& g){
  if(b==0){x=1;y=0;g=a;}else{eea(b,a%b,y,x,g);y-=(a/b)*x;}
}

long long normalize(long long x){
  while(x<PRIME){
    x+=PRIME;
  }
  return x%PRIME;
}

long long inv(long long x){
  long long inverse,times;
  long long gcd;
  normalize(x);
  eea(x,PRIME,inverse,times,gcd);
  return normalize(inverse);
}

int main(){
  int N;
  long long val=1;
  std::cin>>N;
  for(int i=1;i<N;i++){
    val=(val*inv(i))%PRIME;
    val=(val*(N+i))%PRIME;
  }
  val=(2*val+PRIME-N)%PRIME;
  std::cout<<val<<std::endl;
}