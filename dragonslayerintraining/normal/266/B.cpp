#include <iostream>

int main(){
  int N,T;
  std::cin>>N>>T;
  std::string str;
  std::cin>>str;
  while(T-->0){
    for(int i=1;i<N;i++){
      if((str[i-1]=='B')&&(str[i]=='G')){
	std::swap(str[i-1],str[i]);
	i++;
      }
    }
  }
  std::cout<<str<<std::endl;
  return 0;
}