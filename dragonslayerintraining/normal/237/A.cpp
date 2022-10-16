#include <iostream>
#include <map>

std::map<std::pair<int,int>,int> cnt;
int main(){
  int N;
  std::cin>>N;
  int most=0;
  for(int i=0;i<N;i++){
    int H,M;
    std::cin>>H>>M;
    most=std::max(most,++cnt[std::make_pair(H,M)]);
  }
  std::cout<<most<<std::endl;
  return 0;
}