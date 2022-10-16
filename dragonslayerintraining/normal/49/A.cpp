#include <iostream>
#include <cctype>

int main(){
  std::string ques;
  std::getline(std::cin,ques);
  char last;
  for(int i=0;i<ques.length();i++){
    if(std::isalpha(ques[i])){
      last=std::tolower(ques[i]);
    }
  }
  switch(last){
  case 'a':case 'e':case 'i':case 'o':case 'u':case 'y':
    std::cout<<"YES"<<std::endl;
    break;
  default:
    std::cout<<"NO"<<std::endl;
    break;
  }
  return 0;
}