#include <iostream>
#include <algorithm>

std::string str[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>str[i];
  }
  std::sort(str,str+N,[](std::string a,std::string b){return a.length()<b.length();});
  for(int i=1;i<N;i++){
    if(str[i].find(str[i-1])==std::string::npos){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  std::cout<<"YES"<<std::endl;
  for(int i=0;i<N;i++){
    std::cout<<str[i]<<std::endl;
  }
  return 0;
}