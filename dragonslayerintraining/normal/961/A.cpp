#include <iostream>
#include <algorithm>

int cnt[1000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int X;
    std::cin>>X;
    X--;
    cnt[X]++;
  }
  std::cout<<*std::min_element(cnt,cnt+N)<<std::endl;
  return 0;
}