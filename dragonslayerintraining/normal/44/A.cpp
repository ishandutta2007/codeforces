#include <iostream>
#include <set>

int N;

std::set<std::string> set;

int main(){
  std::cin>>N;
  std::string ign;
  std::getline(std::cin,ign);
  for(int i=0;i<N;i++){
    std::string name;
    std::getline(std::cin,name);
    set.insert(name);
  }
  std::cout<<set.size()<<std::endl;
  return 0;
}