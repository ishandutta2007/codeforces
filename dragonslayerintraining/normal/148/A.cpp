#include <iostream>

int main(){
  int K,L,M,N,D;
  std::cin>>K>>L>>M>>N>>D;
  int cnt=0;
  for(int i=1;i<=D;i++){
    if((i%K==0)||(i%L==0)||(i%M==0)||(i%N==0)){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}