#include <iostream>

int N;
int prefix[101];

int main(){
  std::cin>>N;
  for(int i=1;i<=N;i++){
    std::cin>>prefix[i];
    prefix[i]+=prefix[i-1];
  }
  int S,T;
  std::cin>>S>>T;
  S--,T--;
  if(S>T){
    std::swap(S,T);
  }
  int dist=prefix[T]-prefix[S];
  std::cout<<std::min(dist,prefix[N]-dist)<<std::endl;
  return 0;
}