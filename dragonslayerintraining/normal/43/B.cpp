#include <iostream>
#include <set>

std::multiset<char> letters;

int main(){
  std::string heading;
  std::string message;
  std::getline(std::cin,heading);
  std::getline(std::cin,message);
  
  for(int i=0;i<heading.size();i++){
    letters.insert(heading[i]);
  }
  for(int i=0;i<message.size();i++){
    if(message[i]==' '){
      continue;
    }
    if(letters.count(message[i])){
      letters.erase(letters.find(message[i]));
    }else{
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}