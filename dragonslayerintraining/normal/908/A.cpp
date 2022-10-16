#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int cnt=0;
  for(char c:str){
    if((c=='a')||
       (c=='e')||
       (c=='i')||
       (c=='o')||
       (c=='u')||
       (c=='1')||
       (c=='3')||
       (c=='5')||
       (c=='7')||
       (c=='9')){
      cnt++;
    }  
  }
  std::cout<<cnt<<std::endl;
  return 0;
}