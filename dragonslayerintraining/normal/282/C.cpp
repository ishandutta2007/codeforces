#include <iostream>

int main(){
  std::string A,B;
  std::cin>>A>>B;
  if(A.length()!=B.length()){
    std::cout<<"NO"<<std::endl;
  }else{
    int flag=1;
    for(char c:A){
      if(c=='1'){
	flag^=1;
	break;
      }
    }
    for(char c:B){
      if(c=='1'){
	flag^=1;
	break;
      }
    }
    std::cout<<(flag?"YES":"NO")<<std::endl;
  }
  
  return 0;
}