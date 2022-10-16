#include <iostream>

int main(){
  int K,L;
  std::cin>>K>>L;
  int cnt=-1;
  for(;L>1;L/=K,cnt++){
    if(L%K!=0){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  if(cnt<0){
    std::cout<<"NO"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
    std::cout<<cnt<<std::endl;
  }
  return 0;
}