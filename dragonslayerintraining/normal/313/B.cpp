#include <iostream>

int as[100000];

int main(){
  std::string str;
  std::cin>>str;
  for(int i=1;i<str.length();i++){
    as[i]=(str[i]==str[i-1]);
  }
  for(int i=1;i<str.length();i++){
    as[i]+=as[i-1];
  }
  int M;
  std::cin>>M;
  for(int i=0;i<M;i++){
    int L,R;
    std::cin>>L>>R;
    std::cout<<as[R-1]-as[L-1]<<std::endl;
  }
  return 0;
}