#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int run=0;
  int cnt=0;
  int i;
  for(i=str.length()-1;i>=0;i--){
    if(str[i]=='1'){
      break;
    }else{
      cnt++;
    }
  }
  for(;i>=0;i--){
    if(str[i]=='1'){
      run++;
    }else{
      cnt+=run+1;
      run=1;
    }
  }
  if(run>1){
    cnt+=run+1;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}