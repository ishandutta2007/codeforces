#include <iostream>
#include <algorithm>

bool isprime(int num){
  if(num<2){
    return false;
  }
  for(int i=2;i*i<=num;i++){
    if(num%i==0){
      return false;
    }
  }
  return true;
}

int cnts[256];

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    cnts[str[i]]++;
  }
  char mode=char(std::max_element(cnts,cnts+256)-cnts);
  std::partition(str.begin(),str.end(),[mode](char c){return (c==mode);});
  int left=0,right=str.length();
  std::string ret=str;
  for(int i=0;i<str.length();i++){
    if((i==0)||(((i+1)*2>str.length())&&isprime(i+1))){
      ret[i]=str[--right];
    }else{
      if(str[left]!=mode){
	std::cout<<"NO"<<std::endl;
	return 0;
      }
      ret[i]=str[left++];
    }
  }
  std::cout<<"YES"<<std::endl;
  std::cout<<ret<<std::endl;
  return 0;
}