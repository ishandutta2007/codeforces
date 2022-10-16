#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stdint.h>

const int64_t INF=1e9+7;

std::vector<int64_t> children[100005];
int64_t ss[100005];
int64_t ans=0;

void dfs_even(int64_t node,int64_t min);

void dfs_odd(int64_t node){
  //printf("odd: %I64d\n",ss[node]);
  for(int64_t child:children[node]){
    dfs_even(child,ss[node]);
  }
}

void dfs_even(int64_t node,int64_t min){
  //printf("even: %I64d\n",ss[node]);
  int64_t max=INF;
  for(int64_t child:children[node]){
    max=std::min(max,ss[child]);
    dfs_odd(child);
  }
  if(min>max){
    printf("-1\n");
    exit(0);
  }
  if(children[node].empty()){
    ss[node]=min;
  }else{
    ss[node]=max;
  }
}

void dfs_recover(int64_t node,int64_t up){
  //printf("%I64d: ans+=%I64d-%I64d\n",node,ss[node],up);
  ans+=ss[node]-up;
  for(int64_t child:children[node]){
    dfs_recover(child,ss[node]);
  }
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<N;i++){
    int64_t P;
    scanf("%I64d",&P);
    P--;
    children[P].push_back(i);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&ss[i]);
  }
  dfs_odd(0);
  dfs_recover(0,0);
  printf("%I64d\n",ans);
  return 0;
}