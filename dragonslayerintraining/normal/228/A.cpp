#include <iostream>
#include <set>

std::set<int> set;

int main(){
  for(int i=0;i<4;i++){
    int S;
    std::cin>>S;
    set.insert(S);
  }
  std::cout<<4-set.size()<<std::endl;
  return 0;
}