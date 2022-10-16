#include <iostream>

int common(const char* s1,const char* s2){
  int i;
  for(i=0;(s1[i]==s2[i])&&s1[i];i++);
  return i;
}

int main(){
  std::string str;
  int best=0;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    for(int j=i+1;j<str.length();j++){
      best=std::max(best,common(str.c_str()+i,str.c_str()+j));
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}