#include <iostream>
#include <vector>

int main(){
  int T;
  std::cin>>T;
  while(T-->0){
    int N,K;
    std::cin>>N>>K;
    std::vector<int> xs;
    for(int i=0;i<K;i++){
      int X;
      std::cin>>X;
      xs.push_back(X);
    }
    int worst=0;
    for(int i=1;i<=N;i++){
      int best=1e9;
      for(int x:xs){
	best=std::min(best,std::abs(x-i)+1);
      }
      worst=std::max(worst,best);
    }
    std::cout<<worst<<std::endl;
  }
  return 0;
}