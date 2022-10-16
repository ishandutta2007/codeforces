#include <iostream>

int K,A,B;

std::string str;

int main(){
  std::cin>>K>>A>>B;
  std::cin>>str;
  if((K*A>str.length())||(K*B<str.length())){
    std::cout<<"No solution"<<std::endl;
    return 0;
  }
  int left=str.length();
  int ac=0;
  for(int i=0;i<K;i++){
    int len=std::max(A,std::min(left-(K-i-1)*A,B));
    left-=len;
    for(int j=0;j<len;j++){
      std::cout<<str[ac+j];
    }
    ac+=len;
    std::cout<<std::endl;
  }
  return 0;
}