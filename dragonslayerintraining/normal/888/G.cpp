#include <iostream>
#include <algorithm>
#include <cassert>
#include <stdint.h>

int64_t as[200000];

int64_t bridge(int64_t mask0,int64_t mask1,int64_t k,int64_t* begin0,int64_t* end0,int64_t* begin1,int64_t* end1){
  //std::cout<<"bridge "<<k<<" ["<<*begin0<<","<<*end0<<") ["<<*begin1<<","<<*end1<<")"<<std::endl;
  if(begin0==end0||begin1==end1) return 1<<30;
  if(k<0) return *begin0^*begin1;
  int64_t* mid0=std::lower_bound(begin0,end0,mask0|(1<<k));
  int64_t* mid1=std::lower_bound(begin1,end1,mask1|(1<<k));
  int64_t best=std::min(bridge(mask0,mask1,k-1,begin0,mid0,begin1,mid1),
		    bridge(mask0|(1<<k),mask1|(1<<k),k-1,mid0,end0,mid1,end1));
  if(best<(1<<30)) return best;
  return std::min(bridge(mask0,mask1|(1<<k),k-1,begin0,mid0,mid1,end1),
		  bridge(mask0|(1<<k),mask1,k-1,mid0,end0,begin1,mid1));
}

int64_t solve(int64_t mask,int64_t k,int64_t* begin,int64_t* end){
  if(k<0) return 0;
  //std::cout<<"solve "<<k<<" ["<<*begin<<","<<*end<<")"<<std::endl;
  assert(begin!=end);
  int64_t* mid=std::lower_bound(begin,end,mask|(1<<k));
  if(begin==mid) return solve(mask|(1<<k),k-1,mid,end);
  if(mid==end) return solve(mask,k-1,begin,mid);
  return solve(mask,k-1,begin,mid)+solve(mask|(1<<k),k-1,mid,end)+bridge(mask,mask|(1<<k),k-1,begin,mid,mid,end);
}

int main(){
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  std::cout<<solve(0,29,as,as+N)<<std::endl;
  return 0;
}