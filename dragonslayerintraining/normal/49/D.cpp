#include <iostream>

int N;
std::string str;

int main(){
  std::cin>>N>>str;
  for(int i=0;i<str.length();i++){
    str[i]-='0';
  }
  int cnt=0;
  for(int i=0;i<str.length();i++){
    if(str[i]==i%2){
      cnt++;
    }
  }
  std::cout<<std::min(cnt,N-cnt)<<std::endl;
  return 0;
}