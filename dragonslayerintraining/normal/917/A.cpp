#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int cnt=0;
  for(int i=0;i<str.length();i++){
    int low=0,high=0;
    for(int j=i;j<str.length();j++){
      if(str[j]=='('){
	low++,high++;
      }else if(str[j]==')'){
	low--,high--;
      }else{
	low--,high++;
      }
      if(low<0) low+=2;
      if(low>high) break;
      if(low==0) cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}