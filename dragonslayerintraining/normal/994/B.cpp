#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <stdint.h>

int64_t ps[100000];
int64_t cs[100000];

std::map<int64_t,std::vector<int64_t> > ks;
int64_t ans[100000];

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&ps[i]);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&cs[i]);
  }
  for(int64_t i=0;i<N;i++){
    ks[ps[i]].push_back(i);
  }
  std::multiset<int64_t> top;
  int64_t score=0;
  for(auto pair:ks){
    for(int64_t i:pair.second){
      ans[i]=score;
    }
    for(int64_t i:pair.second){
      top.insert(cs[i]);
      score+=cs[i];
      if(top.size()>K){
	score-=*top.begin();
	top.erase(top.begin());
      }
    }
  }
  for(int64_t i=0;i<N;i++){
    if(i) printf(" ");
    printf("%I64d",cs[i]+ans[i]);
  }
  printf("\n");
  return 0;
}