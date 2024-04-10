#include <iostream>
#include <set>
#include <cctype>

std::set<char> vowels;

int main(){
  vowels.insert('a');
  vowels.insert('e');
  vowels.insert('i');
  vowels.insert('o');
  vowels.insert('u');
  vowels.insert('y');
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    if(std::isupper(str[i])){
      str[i]=tolower(str[i]);
    }
    if(vowels.count(str[i])){
      continue;
    }
    std::cout<<"."<<str[i];
  }
  std::cout<<std::endl;
  return 0;
}