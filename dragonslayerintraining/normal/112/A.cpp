#include <iostream>

int main(){
  std::string s1,s2;
  std::cin>>s1>>s2;
  for(int i=0;i<s1.length();i++){
    s1[i]=std::tolower(s1[i]);
  }
  for(int i=0;i<s2.length();i++){
    s2[i]=std::tolower(s2[i]);
  }
  int n=s1.compare(s2);
  if(n<0){
    std::cout<<-1<<std::endl;
  }else if(n>0){
    std::cout<<1<<std::endl;
  }else{
    std::cout<<0<<std::endl;
  }
  return 0;
}