#include <iostream>
#include <set>
#include <stdint.h>

int main(){
  int N,K;
  std::cin>>N>>K;
  if(K==1){
    std::cout<<N<<std::endl;
    return 0;
  }
  std::set<int64_t> set;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    set.insert(A);
  }
  for(std::set<int64_t>::iterator it=set.begin();it!=set.end();it++){
    set.erase(*it*K);
  }
  std::cout<<set.size()<<std::endl;
  return 0;
}