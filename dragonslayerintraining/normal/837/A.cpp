#include <iostream>
#include <cctype>

int main(){
  int N;
  std::cin>>N;
  std::string line;
  std::getline(std::cin,line);
  std::getline(std::cin,line);
  int cnt=0;
  int best=0;
  for(char c:line){
    if(c==' '){
      cnt=0;
    }else if(std::isupper(c)){
      cnt++;
      best=std::max(best,cnt);
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}