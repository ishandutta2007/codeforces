#include <iostream>
#include <algorithm>

int N;
int as[100000];

int max=0,min=1e9;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
    max=std::max(max,as[i]);
    min=std::min(min,as[i]);
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if((as[i]<max)&&(as[i]>min)){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  
  return 0;
}