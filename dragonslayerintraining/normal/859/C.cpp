#include <iostream>

int as[100];
int ds[100],es[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  ds[N]=0;
  es[N]=0;
  for(int i=N-1;i>=0;i--){
    ds[i]=std::max(ds[i+1],es[i+1]+as[i]);
    es[i]=std::min(ds[i+1],es[i+1]+as[i]);
  }
  std::cout<<es[0]<<" "<<ds[0]<<std::endl;
  return 0;
}