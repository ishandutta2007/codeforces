#include <cstdio>
#include <vector>
#include <stdint.h>

int64_t N,M;

int64_t cs[100000];

std::vector<int64_t> conn[100000];

int64_t dfs(int64_t node){
  int64_t best=cs[node];
  cs[node]=-1;
  for(int64_t child:conn[node]){
    if(cs[child]!=-1){
      best=std::min(best,dfs(child));
    }
  }
  return best;
}

int main(){
  scanf("%ld %ld",&N,&M);
  for(int64_t i=0;i<N;i++){
    scanf("%ld",&cs[i]);
  }
  for(int64_t i=0;i<M;i++){
    int64_t X,Y;
    scanf("%ld %ld",&X,&Y);
    X--,Y--;
    conn[X].push_back(Y);
    conn[Y].push_back(X);
  }
  int64_t total=0;
  for(int64_t i=0;i<N;i++){
    if(cs[i]!=-1){
      total+=dfs(i);
    }
  }
  printf("%I64d\n",total);
  return 0;
}