#include <iostream>
#include <map>

std::map<char,int> counts;

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    counts[str[i]]++;
  }
  long long cnt=0;
  for(std::map<char,int>::iterator it=counts.begin();it!=counts.end();it++){
    cnt+=(long long)(it->second)*it->second;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}