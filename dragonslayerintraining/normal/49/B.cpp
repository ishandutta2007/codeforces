#include <iostream>

int getdigit(char c){
  return std::isdigit(c)?(c-'0'):(c-'A'+10);
}

int numdigits(int num,int base){
  int cnt=0;
  for(;num>0;num/=base){
    cnt++;
  }
  return cnt;
}

int main(){
  std::string s1,s2;
  std::cin>>s1>>s2;
  int base=0;
  for(int i=0;i<s1.length();i++){
    base=std::max(base,getdigit(s1[i]));
  }
  for(int i=0;i<s2.length();i++){
    base=std::max(base,getdigit(s2[i]));
  }
  base++;

  int num1=0,num2=0;
  for(int i=0;i<s1.length();i++){
    num1=num1*base+getdigit(s1[i]);
  }
  for(int i=0;i<s2.length();i++){
    num2=num2*base+getdigit(s2[i]);
  }
  std::cout<<numdigits(num1+num2,base)<<std::endl;
  return 0;
}