#include <iostream>

int cnt[256];

int main(){
  std::string S;
  std::cin>>S;
  char curr='a';
  for(char c:S){
    if(c!=curr){
      curr++;
    }
    if(c!=curr||curr>'c'){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
    cnt[c]++;
  }
  if((cnt['a']>0)&&(cnt['b']>0)&&
     (cnt['c']==cnt['a']||cnt['c']==cnt['b'])){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}