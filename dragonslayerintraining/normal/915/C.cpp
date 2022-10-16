#include <iostream>
#include <algorithm>
#include <stdint.h>

int64_t to_int64_t(std::string N){
  int64_t num=0;
  for(char c:N){
    num=num*10+c-'0';
  }
  return num;
}

int main(){
  std::string A;
  int64_t B;
  std::cin>>A>>B;
  for(int64_t i=0;i<A.size();i++){
    std::sort(A.begin()+i,A.end(),std::greater<char>());
    std::sort(A.begin()+i+1,A.end());
    while(to_int64_t(A)>B){
      std::prev_permutation(A.begin()+i,A.end());
      std::sort(A.begin()+i+1,A.end());
    }
  }
  std::cout<<A<<std::endl;
  return 0;
}