#include <iostream>
#include <algorithm>

int main(){
  std::string str;
  std::string bob;
  std::cin>>str>>bob;
  std::sort(str.begin(),str.end());
  if(str[0]=='0'){
    for(int i=1;i<str.length();i++){
      if(str[i]!='0'){
	std::swap(str[0],str[i]);
	break;
      }
    }
  }
  if(str!=bob){
    std::cout<<"WRONG_ANSWER"<<std::endl;
  }else{
    std::cout<<"OK"<<std::endl;
  }
  return 0;
}