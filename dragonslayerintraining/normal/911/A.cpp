#include <iostream>
#include <algorithm>

int as[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int min=*std::min_element(as,as+N);
  int last=-1e9;
  int dist=1e9;
  for(int i=0;i<N;i++){
    if(as[i]==min){
      dist=std::min(dist,i-last);
      last=i;
    }
  }
  std::cout<<dist<<std::endl;
  return 0;
}