#include <iostream>
#include <set>

std::set<char> set;

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    set.insert(str[i]);
  }
  std::cout<<((set.size()%2)?"IGNORE HIM!":"CHAT WITH HER!")<<std::endl;
  return 0;
}