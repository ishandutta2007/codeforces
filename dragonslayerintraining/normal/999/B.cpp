#include <iostream>
#include <algorithm>

int main(){
  int N;
  std::cin>>N;
  std::string str;
  std::cin>>str;
  for(int i=1;i<=N;i++){
    if(N%i==0){
      std::reverse(str.begin(),str.begin()+i);
    }
  }
  std::cout<<str<<std::endl;
  return 0;
}