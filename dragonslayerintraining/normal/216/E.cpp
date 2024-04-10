#include <iostream>
#include <map>
#include <stdint.h>

std::map<int64_t,int64_t> set;

int main(){
  int64_t K,B,N;
  
  std::cin>>K>>B>>N;
  int64_t ac=0;
  int64_t cnt=0;
  int64_t zlen=0;
  int64_t zstr=0;
  set[0]++;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    if(A==0){
      zlen++;
      zstr+=zlen;
    }else{
      zlen=0;
    }
    ac=(ac+A)%(K-1);
    cnt+=set[(ac-B+2*(K-1))%(K-1)];
    set[ac]++;
  }
  if(B==0){
    std::cout<<zstr<<std::endl;
  }else if(B==K-1){
    std::cout<<cnt-zstr<<std::endl;
  }else{
    std::cout<<cnt<<std::endl;
  }
  return 0;
}