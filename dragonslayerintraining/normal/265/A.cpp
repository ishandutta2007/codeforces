#include <iostream>

int main(){
  std::string S,T;
  std::cin>>S>>T;
  int j=0;
  for(int i=0;i<T.size();i++){
    if(T[i]==S[j]){
      j++;
    }
  }
  std::cout<<j+1<<std::endl;
  return 0;
}