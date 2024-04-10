#include <iostream>

int main(){
  std::string a,b;
  std::cin>>a>>b;
  int e47=0,e74=0;
  for(int i=0;i<a.size();i++){
    if((a[i]=='4')&&(b[i]=='7')){
      e47++;
    }
    if((a[i]=='7')&&(b[i]=='4')){
      e74++;
    }
  }
  std::cout<<std::max(e47,e74)<<std::endl;
  return 0;
}