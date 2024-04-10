#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int rem=0;
  int count=0;
  for(int i=0;i<str.length();i++){
    if(str[i]=='('){
      count++;
    }else{
      count--;
    }
    if(count<0){
      rem+=-count;
      count=0;
    }
  }
  rem+=count;
  std::cout<<str.length()-rem<<std::endl;
  return 0;
}