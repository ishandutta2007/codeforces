#include <iostream>

int main(){
  std::string S,T;
  std::cin>>S>>T;
  std::string best="\xff";
  for(int i=1;i<=S.size();i++){
    for(int j=1;j<=T.size();j++){
      best=std::min(best,S.substr(0,i)+T.substr(0,j));
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}