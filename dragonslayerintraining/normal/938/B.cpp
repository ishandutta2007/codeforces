#include <iostream>

int as[100002];

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<=N;i++){
    std::cin>>as[i];    
  }
  as[0]=1;
  as[N+1]=1000000;
  int best=1000000;
  for(int i=0;i<=N;i++){
    best=std::min(best,std::max(as[i]-1,1000000-as[i+1]));
  }
  std::cout<<best<<std::endl;
  return 0;
}