#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v;

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i+=2){
    v.push_back(str[i]-'0');
  }
  std::sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    if(i>0){
      std::cout<<"+";
    }
    std::cout<<char('0'+v[i]);
  }
  std::cout<<std::endl;
  return 0;
}