#include <iostream>
#include <algorithm>

int as[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int min=*std::min_element(as,as+N);
  int max=*std::max_element(as,as+N);
  int cost=0;
  for(int i=0;i<N;i++){
    if(as[i]==max){
      std::rotate(as,as+i,as+i+1);
      cost+=i;
      break;
    }
  }
  for(int i=N-1;i>=0;i--){
    if(as[i]==min){
      std::rotate(as+i,as+i+1,as+N);
      cost+=N-i-1;
      break;
    }
  }
  std::cout<<cost<<std::endl;
  return 0;
}