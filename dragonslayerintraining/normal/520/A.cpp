#include <iostream>
#include <cctype>
#include <set>

std::set<int> used;

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  for(int i=0;i<N;i++){
    used.insert(tolower(str[i]));
  }
  std::cout<<((used.size()==26)?"YES":"NO")<<std::endl;
  return 0;
}