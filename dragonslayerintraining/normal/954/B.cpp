#include <iostream>

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  for(int l=N/2;l>0;l--){
    if(str.substr(0,l)==str.substr(l,l)){
      std::cout<<N-l+1<<std::endl;
      return 0;
    }
  }
  std::cout<<N<<std::endl;
  return 0;
}