#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  N--;
  int low=0,high=1e9;
  for(int i=0;i<M;i++){
    int K,F;
    std::cin>>K>>F;
    K--,F--;
    low=std::max(low,K/(F+1));
    if(F!=0){
      high=std::min(high,K/F);
    }
  }
  if(N/(low+1)==N/high){
    std::cout<<N/high+1<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}