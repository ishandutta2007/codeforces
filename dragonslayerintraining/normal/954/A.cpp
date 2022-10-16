#include <iostream>

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  int len=0;
  for(int i=0;i<N;i++){
    if((i+1<N)&&(str[i]!=str[i+1])){
      len++;
      i++;
    }else{
      len++;
    }
  }
  std::cout<<len<<std::endl;
  return 0;
}