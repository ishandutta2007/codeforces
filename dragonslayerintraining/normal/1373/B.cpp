#include <iostream>
#include <algorithm>

int main(){
  int T;
  std::cin>>T;
  while(T--){
    std::string s;
    std::cin>>s;
    int x=std::count(s.begin(),s.end(),'0');
    int moves=std::min<int>(x,s.length()-x);
    printf("%s\n",(moves&1)?"DA":"NET");
  }
}