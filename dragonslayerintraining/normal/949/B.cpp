#include <iostream>
#include <stdint.h>

int64_t query(int64_t k,int64_t x){
  if(x==0) return 0;
  if(x&1) return (1LL<<(k-1))+(x>>1);
  return query(k-1,x>>1);
}

int main(){
  int64_t N,Q;
  std::cin>>N>>Q;
  int64_t k;
  for(k=0;(1LL<<k)<=N;k++);
  k--;
  int64_t extra=(N-(1LL<<k))*2;
  for(int64_t i=0;i<Q;i++){
    int64_t X;
    std::cin>>X;
    if(X<=extra){
      std::cout<<N-query(k+1,extra-X)<<std::endl;
    }else{
      std::cout<<N-query(k,(1LL<<k)+extra-X)<<std::endl;
    }
  }
  return 0;
}