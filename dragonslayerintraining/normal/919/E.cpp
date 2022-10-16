#include <iostream>
#include <stdint.h>

int64_t inv[1000003];

int main(){
  int64_t A,B,P,X;
  std::cin>>A>>B>>P>>X;
  inv[1]=1;
  for(int64_t i=2;i<P;i++){
    inv[i]=(P-P/i)*inv[P%i]%P;
  }
  int64_t a_n=1;
  int64_t cnt=0;
  for(int64_t i=0;i<P-1;i++,a_n=a_n*A%P){
    cnt+=(X-((i+P-B*inv[a_n]%P)%P*(P-1)+i)+P*(P-1))/P/(P-1);
  }
  std::cout<<cnt<<std::endl;
  return 0;
}