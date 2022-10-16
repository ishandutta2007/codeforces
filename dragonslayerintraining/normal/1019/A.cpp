#include <cstdio>
#include <vector>
#include <stdint.h>
#include <functional>
#include <algorithm>

std::vector<int64_t> cs[3005];

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  
  for(int64_t i=0;i<N;i++){
    int64_t P,C;
    scanf("%I64d %I64d",&P,&C);
    P--;
    cs[P].push_back(C);
  }
  for(int64_t i=0;i<M;i++){
    std::sort(cs[i].begin(),cs[i].end(),std::greater<int64_t>());
  }
  int64_t best=1e15;
  for(int64_t v=1;v<=N;v++){
    //min cost to win with v votes
    int64_t cost=0;
    int64_t have=cs[0].size();
    for(int64_t i=1;i<M;i++){
      for(int64_t j=v-1;j<cs[i].size();j++){
	cost+=cs[i][j];
	have++;
      }
    }
    std::vector<int64_t> rest;
    for(int64_t i=1;i<M;i++){
      for(int64_t j=0;j<std::min<int64_t>(v-1,cs[i].size());j++){
	rest.push_back(cs[i][j]);
      }
    }
    std::sort(rest.begin(),rest.end(),std::greater<int64_t>());
    while(have<v){
      cost+=rest.back();
      rest.pop_back();
      have++;
    }
    best=std::min(best,cost);
  }
  printf("%I64d\n",best);
  return 0;
}