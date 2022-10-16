#include <iostream>

int as[5001];
int bs[5001];

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    as[i+1]=as[i]+(str[i]=='a');
  }
  for(int i=0;i<str.length();i++){
    bs[i+1]=bs[i]+(str[i]=='b');
  }
  int best=0;
  for(int i=0;i<=str.length();i++){
    for(int j=i;j<=str.length();j++){
      best=std::max(best,as[i]+bs[j]-bs[i]+as[str.length()]-as[j]);
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}