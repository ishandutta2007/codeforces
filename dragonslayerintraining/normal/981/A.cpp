#include <iostream>
#include <algorithm>
bool ispal(std::string str){
  std::string rev=str;
  std::reverse(rev.begin(),rev.end());
  return str==rev;
}

int main(){
  std::string str;
  std::cin>>str;
  int best=0;
  for(int len=1;len<=str.length();len++){
    for(int i=0;i+len<=str.length();i++){
      std::string tmp=str.substr(i,len);
      if(!ispal(tmp)){
	best=std::max(best,len);
      }
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}