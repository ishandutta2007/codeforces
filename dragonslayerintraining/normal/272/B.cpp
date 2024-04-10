#include <iostream>
#include <stdint.h>

int64_t A[32];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int X;
    std::cin>>X;
    int S=0;
    for(;X>0;X>>=1){
      S+=(X&1);
    }
    A[S]++;
  }
  int64_t total=0;
  for(int i=0;i<32;i++){
    total+=A[i]*(A[i]-1)/2;
  }
  std::cout<<total<<std::endl;
  return 0;
}