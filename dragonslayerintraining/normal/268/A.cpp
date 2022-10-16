#include <iostream>
#include <map>

int N;

std::map<int,int> hs;

int as[100];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int H;
    std::cin>>H>>as[i];
    hs[H]++;
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    cnt+=hs[as[i]];
  }
  std::cout<<cnt<<std::endl;
  return 0;
}