#include <iostream>

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  std::cout<<(((str[0]=='S')&&(str[str.length()-1]=='F'))?"YES":"NO")<<std::endl;
  return 0;
}