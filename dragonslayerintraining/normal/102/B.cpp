#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  if(str.length()==1){
    std::cout<<0<<std::endl;
    return 0;
  }
  int sum=0;
  for(int i=0;i<str.length();i++){
    sum+=str[i]-'0';
  }
  int cnt=1;
  while(sum>=10){
    int sum2=0;
    for(;sum>0;sum/=10){
      sum2+=sum%10;
    }
    sum=sum2;
    cnt++;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}