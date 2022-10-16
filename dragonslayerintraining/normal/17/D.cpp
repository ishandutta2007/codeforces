#include <iostream>
#include <stdint.h>

int main(){
  std::string Bstr,Nstr;
  int64_t C;
  std::cin>>Bstr>>Nstr>>C;
  int64_t B=0;
  for(char c:Bstr){
    B=(10*B+(c-'0'))%C;
  }
  int i;
  for(i=Nstr.length()-1;Nstr[i]=='0';i--){
    Nstr[i]='9';
  }
  Nstr[i]--;
  int64_t ac=1;
  for(char c:Nstr){
    int64_t ac2=1;
    for(int i=0;i<10;i++){
      ac2=(ac2*ac)%C;
    }
    ac=ac2;
    
    for(char i='0';i<c;i++){
      ac=(ac*B)%C;
    }
  }
  ac=(ac*(B+C-1))%C;
  if(ac>0){
    std::cout<<ac<<std::endl;
  }else{
    std::cout<<C<<std::endl;
  }
  return 0;
}