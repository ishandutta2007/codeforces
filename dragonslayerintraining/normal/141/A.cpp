#include <iostream>
#include <algorithm>

int main(){
  std::string guest,host,pile;
  std::cin>>guest>>host>>pile;
  std::string cat=guest+host;
  std::sort(cat.begin(),cat.end());
  std::sort(pile.begin(),pile.end());
  std::cout<<((cat==pile)?"YES":"NO")<<std::endl;
  return 0;
}