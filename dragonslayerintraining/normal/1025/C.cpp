#include <iostream>

std::string str;

int main(){
  std::cin>>str;
  str=str+str;
  int run=1;
  int ans=1;
  for(int i=1;i<str.length();i++){
    if(str[i]!=str[i-1]){
      run++;
      ans=std::max(ans,run);
    }else{
      run=1;
    }
  }
  std::cout<<std::min<int>(ans,str.length()/2)<<std::endl;
  return 0;
}