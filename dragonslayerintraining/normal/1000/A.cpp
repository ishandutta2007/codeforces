#include <iostream>
#include <map>

std::map<std::string,int> cnt;


int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string A;
    std::cin>>A;
    cnt[A]++;
  }
  for(int i=0;i<N;i++){
    std::string A;
    std::cin>>A;
    cnt[A]--;
  }
  int cost=0;
  for(auto it:cnt){
    if(it.second>0) cost+=it.second;
  }
  std::cout<<cost<<std::endl;
  return 0;
}