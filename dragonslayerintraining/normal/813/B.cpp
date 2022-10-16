#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

std::vector<int64_t> as,bs;

std::vector<int64_t> cs;

int main(){
  int64_t X,Y,L,R;
  std::cin>>X>>Y>>L>>R;
  as.push_back(1);
  while(as.back()<=R/X){
    as.push_back(as.back()*X);
  }
  bs.push_back(1);
  while(bs.back()<=R/Y){
    bs.push_back(bs.back()*Y);
  }
  for(int64_t a:as){
    for(int64_t b:bs){
      int64_t sum=a+b;
      if((sum>=L)&&(sum<=R)){
	cs.push_back(sum);
      }
    }
  }
  cs.push_back(L-1);
  cs.push_back(R+1);
  std::sort(cs.begin(),cs.end());
  int64_t best=0;
  for(int64_t i=1;i<cs.size();i++){
    best=std::max(best,cs[i]-cs[i-1]-1);
  }
  std::cout<<best<<std::endl;
  return 0;
}