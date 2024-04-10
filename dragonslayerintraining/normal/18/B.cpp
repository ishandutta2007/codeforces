#include <iostream>

int main(){
  long long N,D,M,L;
  std::cin>>N>>D>>M>>L;
  for(int i=0;;i++){
    long long x=i*D;
    if((x%M>L)||(x/M>=N)){
      std::cout<<x<<std::endl;
      return 0;
    }
    if((i>0)&&(x%M==0)){
      std::cout<<(M*N+D-1)/D*D<<std::endl;
      return 0;
    }
  }
  return 0;
}