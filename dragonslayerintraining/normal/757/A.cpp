#include <iostream>

std::string str;

int occur[256];

int main(){
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    occur[str[i]]++;
  }
  int total=1e9;
  total=std::min(total,occur['B']);
  total=std::min(total,occur['u']/2);
  total=std::min(total,occur['l']);
  total=std::min(total,occur['b']);
  total=std::min(total,occur['a']/2);
  total=std::min(total,occur['s']);
  total=std::min(total,occur['r']);
  std::cout<<total<<std::endl;
  return 0;
}