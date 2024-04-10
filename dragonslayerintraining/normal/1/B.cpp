#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdio>

std::string encode(int n){
  std::string ret;
  while(n>0){
    if(n%26==0){
      ret+='Z';
      n=n/26-1;
    }else{
      ret+=(n%26-1+'A');
      n=n/26;
    }
  }
  std::reverse(ret.begin(),ret.end());
  return ret;
}

void convert(std::string str){
  int row,col;
  if(sscanf(str.c_str(),"R%dC%d",&row,&col)>=2){
    std::cout<<encode(col)<<row<<std::endl;
  }else{
    row=0,col=0;
    int i;
    for(i=0;std::isalpha(str[i]);i++){
      col=col*26+str[i]-'A'+1;
    }
    for(;i<str.length();i++){
      row=row*10+str[i]-'0';
    }
    std::cout<<"R"<<row<<"C"<<col<<std::endl;
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    convert(str);
  }
  return 0;
}