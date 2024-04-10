#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  std::string str2;
  for(int i=0;i<str.length();i++){
    if(str.compare(i,3,"WUB")){
      str2+=str[i];
    }else{
      i+=2;
      if((str2.size()>0)&&(str2[str2.size()-1]!=' ')){
	str2+=' ';
      }
    }
  }
  if(str2[str2.size()-1]==' '){
    str2.resize(str2.size()-1);
  }
  std::cout<<str2<<std::endl;
  return 0;
}