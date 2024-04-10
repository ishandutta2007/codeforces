#include <iostream>

int cntvwls(std::string str){
  int cnt=0;
  for(int i=0;i<str.length();i++){
    switch(str[i]){
    case 'a':case 'e':case 'i':case 'o':case 'u':
      cnt++;
    }
  }
  return cnt;
}

int main(){
  std::string l1,l2,l3;
  std::getline(std::cin,l1);
  std::getline(std::cin,l2);
  std::getline(std::cin,l3);
  if((cntvwls(l1)==5)&&(cntvwls(l2)==7)&&(cntvwls(l3)==5)){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}