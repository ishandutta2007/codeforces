#include <iostream>
#include <stdint.h>

const int64_t MOD=998244353;

int64_t fact[5001];
int64_t inv[5001];
int64_t invfact[5001];

int64_t choose(int64_t n,int64_t k){
  return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

int64_t solve(int64_t A,int64_t B){
  int64_t sum=0;
  for(int64_t k=0;k<=std::min(A,B);k++){
    sum=(sum+choose(A,k)*choose(B,k)%MOD*fact[k])%MOD;
  }
  return sum;
}

int main(){
  fact[0]=1;
  invfact[0]=1;
  inv[0]=0;
  inv[1]=1;
  for(int64_t i=2;i<=5000;i++){
    inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
  }
  for(int64_t i=1;i<=5000;i++){
    fact[i]=fact[i-1]*i%MOD;
    invfact[i]=invfact[i-1]*inv[i]%MOD;
    //std::cout<<i<<" "<<inv[i]<<" "<<fact[i]<<" "<<invfact[i]<<" "
    //	     <<i*inv[i]%MOD<<" "<<fact[i]*invfact[i]%MOD<<std::endl;
  }
  int64_t A,B,C;
  std::cin>>A>>B>>C;
  std::cout<<solve(A,B)*solve(A,C)%MOD*solve(B,C)%MOD<<std::endl;
  return 0;
}