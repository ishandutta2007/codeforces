#include <iostream>
#include <set>

int main(){
  std::set<char> set;
  while(std::cin.peek()!='\n'){
    char c=std::cin.get();
    if(isalpha(c)){
      set.insert(c);
    }
  }
  std::cout<<set.size()<<std::endl;
  return 0;
}