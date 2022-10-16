#include <iostream>
#include <algorithm>

int N;

int cnt[3];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int num;
    std::cin>>num;
    cnt[num%3]++;
  }
  std::cout<<std::min(cnt[1],cnt[2])+cnt[0]/2<<std::endl;
  return 0;
}