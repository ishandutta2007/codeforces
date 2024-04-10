#include <iostream>
#include <algorithm>

int main(){
  std::string str;
  std::cin>>str;
  std::string rev=str;
  std::reverse(rev.begin(),rev.end());
  std::cout<<str+rev<<std::endl;
  return 0;
}