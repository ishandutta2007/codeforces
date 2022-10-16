#include <iostream>
#include <vector>

std::vector<char> str;

int main(){
  char c;
  while((c=std::cin.get())!='\n'){
    if((!str.empty())&&(str.back()==c)){
      str.pop_back();
    }else{
      str.push_back(c);
    }
  }
  for(int i=0;i<str.size();i++){
    std::cout<<str[i];
  }
  std::cout<<std::endl;
  return 0;
}