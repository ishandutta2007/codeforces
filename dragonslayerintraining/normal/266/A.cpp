#include <iostream>

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  int cnt=0;
  for(int i=1;i<str.length();i++){
    if(str[i]==str[i-1]){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}