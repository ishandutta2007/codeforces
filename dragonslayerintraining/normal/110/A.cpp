#include <iostream>

bool islucky(int N){
  if(N==0){
    return true;
  }else{
    switch(N%10){
    case 4:case 7:return islucky(N/10);
    }
  }
  return false;
}

int main(){
  std::string str;
  std::cin>>str;
  int cnt=0;
  for(int i=0;i<str.length();i++){
    if((str[i]=='4')||(str[i]=='7')){
      cnt++;
    }
  }
  if((cnt>0)&&islucky(cnt)){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}