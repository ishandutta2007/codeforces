#include <iostream>

long long xorsum(long long n){
  if((n&1)==0){
    return n|((n&2)>>1);
  }else{
    return 1&~((n&2)>>1);
  }
}

int main(){
  long long N;
  std::cin>>N;
  long long ac=0;
  for(long long i=0;i<N;i++){
    long long X,M;
    std::cin>>X>>M;
    ac^=(xorsum(X+M-1)^xorsum(X-1));
  }
  if(ac==0){
    std::cout<<"bolik"<<std::endl;
  }else{
    std::cout<<"tolik"<<std::endl;
  }
  return 0;
}