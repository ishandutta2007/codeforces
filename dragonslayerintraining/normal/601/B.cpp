#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <stdint.h>

int as[100000];

int main(){
  int N,Q;
  std::cin>>N>>Q;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int i=0;i<N-1;i++){
    as[i]=std::abs(as[i+1]-as[i]);
  }
  for(int q=0;q<Q;q++){
    int L,R;
    std::cin>>L>>R;
    L--,R--;
    std::vector<int> bs;
    for(int i=L;i<R;i++){
      bs.push_back(as[i]);
    }
    bs.push_back(1e9);
    int64_t ac=0;
    std::vector<std::pair<int,int> > stk;
    stk.emplace_back(1e9+1,-1);
    for(int i=0;i<=R-L;i++){
      while(bs[i]>=stk.back().first){
	assert(stk.back().first<1e9+1);
	assert(stk.size()>=2);
	int left=stk.back().second-stk[stk.size()-2].second;
	int right=i-stk.back().second;
	ac+=static_cast<int64_t>(stk.back().first)*left*right;
	stk.pop_back();
      }
      stk.emplace_back(bs[i],i);
    }
    std::cout<<ac<<std::endl;
  }
  return 0;
}