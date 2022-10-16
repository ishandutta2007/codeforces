#include <iostream>
#include <algorithm>

int main(){
  int T;
  std::cin>>T;
  while(T-->0){
    int N;
    std::string S;
    std::cin>>N>>S;
    int del=std::find(S.begin(),S.end(),'8')-S.begin();
    if(S.size()-del>=11){
      std::cout<<"YES"<<std::endl;
    }else{
      std::cout<<"NO"<<std::endl;
    }
  }
  return 0;
}