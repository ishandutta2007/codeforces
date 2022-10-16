#include <iostream>
#include <vector>

std::vector<char> mail;

int main(){
  std::string str;
  bool hasat=false;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    mail.push_back(str[i]);
    int len=mail.size();
    if(i==str.length()-1){
      break;
    }
    if((i>=2)&&(mail.size()>=2)&&(!hasat)){
      if((mail[len-2]=='a')&&(mail[len-1]=='t')){
	mail.pop_back();
	mail.pop_back();
	mail.push_back('@');
	hasat=true;
      }
    }
    if((i>=3)&&(mail.size()>=3)){
      if((mail[len-3]=='d')&&(mail[len-2]=='o')&&(mail[len-1]=='t')){
	mail.pop_back();
	mail.pop_back();
	mail.pop_back();
	mail.push_back('.');
      }
    }
  }
  for(int i=0;i<mail.size();i++){
    std::cout<<mail[i];
  }
  std::cout<<std::endl;
  return 0;
}