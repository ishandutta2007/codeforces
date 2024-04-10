#include <iostream>
#include <stdint.h>

void solve(){
  int64_t N;
  std::cin>>N;
  int64_t low=1,high=N;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(mid*(mid-1)/2>N-mid){
      high=mid;
    }else{
      low=mid;
    }
  }
  std::cout<<std::max((N-low)+std::min(N-low,low*(low-1)/2),
		      (N-high)+std::min(N-high,high*(high-1)/2))<<std::endl;
}

int main(){
  int64_t Q;
  std::cin>>Q;
  for(int64_t i=0;i<Q;i++){
    solve();
  }
  return 0;
}