#include <iostream>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t as[2000];

int64_t inverse[2000];
int64_t combo[2000];

int main(){
  int N,K;
  std::cin>>N>>K;
  inverse[1]=1;
  for(int i=2;i<N;i++){
    inverse[i]=((MOD-MOD/i)*inverse[MOD%i])%MOD;
  }
  combo[0]=1;
  for(int i=1;i<N;i++){
    combo[i]=combo[i-1]*(K-1+i)%MOD*inverse[i]%MOD;
  }
  
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    for(int j=i;j<N;j++){
      as[j]=(as[j]+combo[j-i]*A)%MOD;
    }
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<as[i];
  }
  std::cout<<std::endl;
  return 0;
}