#include <iostream>
#include <cstdio>

int mask[200];

int main(){
  std::string str;
  std::cin>>str;
  for(int i=1;i<=str.length();i++){
    switch(str[i-1]){
    case '.':mask[i]=0;break;
    case 'A':mask[i]=1;break;
    case 'B':mask[i]=2;break;
    case 'C':mask[i]=4;break;
    }
  }
  for(int i=1;i<=str.length();i++){
    if((mask[i-1]|mask[i]|mask[i+1])==7){
      std::cout<<"Yes"<<std::endl;
      return 0;
    }
  }
  std::cout<<"No"<<std::endl;
  return 0;
}