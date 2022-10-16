#include <iostream>
#include <algorithm>

int needed=0;

void solve(int limit){
  int sum=0;
  for(int i=0;i<3;i++){
    int A;
    std::cin>>A;
    sum+=A;
  }
  needed+=(sum+limit-1)/limit;
}

int main(){
  solve(5);
  solve(10);
  int N;
  std::cin>>N;
  if(needed>N){
    std::cout<<"NO"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
  }
  return 0;
}