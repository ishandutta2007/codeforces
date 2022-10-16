#include <iostream>
#include <vector>
#include <algorithm>

long long N;
long long cutoff;
std::vector<long long> factors;

long long gcd(long long a,long long b){
  return (b==0)?a:gcd(b,a%b);
}

void init(){
  long long A,B;
  std::cin>>A>>B;
  N=gcd(A,B);
  for(long long i=1;i*i<=N;i++){
    if(N%i==0){
      factors.push_back(i);
    }
  }
  for(int i=factors.size()-1;i>=0;i--){
    if(factors[i]*factors[i]<N){
      factors.push_back(N/factors[i]);
    }
  }
}

long long query(long long L,long long R){
  if(L>R){
    return -1;
  }
  std::vector<long long>::iterator lp,rp;
  lp=std::lower_bound(factors.begin(),factors.end(),L);
  rp=std::upper_bound(factors.begin(),factors.end(),R);
  if(lp<rp){
    return *(rp-1);
  }else{
    return -1;
  }
}

int main(){
  init();
  long long N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    long long L,R;
    std::cin>>L>>R;
    std::cout<<query(L,R)<<std::endl;
  }
  return 0;
}