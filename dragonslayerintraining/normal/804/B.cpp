#include <iostream>
#include <stdint.h>

int64_t MOD=1e9+7;

int main(){
  std::string str;
  std::cin>>str;
  int64_t pow2=1;
  int64_t cnt=0;
  for(char c:str){
    if(c=='a'){
      pow2=pow2*2%MOD;
    }else{
      cnt=(cnt+pow2-1)%MOD;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}