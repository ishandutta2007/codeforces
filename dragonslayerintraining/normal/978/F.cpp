#include <cstdio>
#include <vector>
#include <stdint.h>
#include <map>

int64_t rs[200000];
std::vector<int64_t> edges[200000];

int64_t ans[200000];

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&rs[i]);
  }
  for(int64_t i=0;i<K;i++){
    int64_t A,B;
    scanf("%I64d %I64d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  std::map<int64_t,std::vector<int64_t> > cps;
  for(int64_t i=0;i<N;i++){
    cps[rs[i]].push_back(i);
  }
  int64_t sum=0;
  for(auto pair:cps){
    for(int64_t i:pair.second){
      ans[i]=sum;
      for(int64_t other:edges[i]){
	if(rs[other]<rs[i]){
	  ans[i]--;
	}
      }
    }
    sum+=pair.second.size();
  }
  for(int64_t i=0;i<N;i++){
    if(i) printf(" ");
    printf("%I64d",ans[i]);
  }
  printf("\n");
  return 0;
}