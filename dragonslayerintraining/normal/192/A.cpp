#include <iostream>
#include <stdint.h>

#define TRI(n) (n*(n+1)/2)

int main(){
  int64_t N;
  std::cin>>N;
  int64_t j;
  for(j=1;TRI(j)<N;j++);
  for(int64_t i=1;TRI(i)<N;i++){
    while(TRI(i)+TRI(j)>N){
      j--;
    }
    if(TRI(i)+TRI(j)==N){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}