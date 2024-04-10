#include <iostream>
#include <algorithm>

int as[200000];
std::string swap;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::cin>>swap;
  int start=0;
  for(int i=0;i<N;i++){
    if(swap[i]!='1'){
      std::sort(as+start,as+i+1);
      start=i+1;
    }
  }
  if(std::is_sorted(as,as+N)){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}