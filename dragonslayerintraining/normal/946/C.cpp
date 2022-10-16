#include <iostream>

int main(){
  std::string S;
  std::cin>>S;
  char target='a';
  for(char& c:S){
    if(c<=target){
      c=target;
      if(target++=='z'){
	std::cout<<S<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"-1"<<std::endl;
  return 0;
}