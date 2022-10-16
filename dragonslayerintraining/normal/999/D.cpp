#include <cstdio>
#include <vector>
#include <stdint.h>

int as[200005];
std::vector<int> cs[200005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    cs[as[i]%M].push_back(i);
  }
  std::vector<int> excess;
  int64_t cost=0;
  for(int k=0;k<2;k++){
    for(int i=0;i<M;i++){
      while(cs[i].size()>N/M){
	excess.push_back(cs[i].back());
	cs[i].pop_back();
      }
      while(cs[i].size()<N/M&&excess.size()){
	int inc=(i-as[excess.back()]%M+M)%M;
	cost+=inc;
	as[excess.back()]+=inc;
	cs[i].push_back(excess.back());
	excess.pop_back();
      }
    }
  }
  printf("%I64d\n",cost);
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}