#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

int64_t N;
int64_t as[100000];
int64_t S;
std::vector<int64_t> edges[100000];

std::pair<int64_t,int64_t> dfs(int64_t node,int64_t parent){
  int64_t first=0;
  std::priority_queue<int64_t> cfirst;
  int64_t czags=0;
  for(int64_t child:edges[node]){
    if(child!=parent){
      std::pair<int64_t,int64_t> c=dfs(child,node);
      cfirst.push(c.first);
      czags+=c.second;
    }
  }
  for(as[node]-=(node!=parent);(as[node]>0)&&!cfirst.empty();as[node]--){
    first+=1+cfirst.top();
    cfirst.pop();
  }
  int64_t move=std::min(as[node],czags);
  as[node]-=move;
  first+=move;
  return std::make_pair(first,as[node]);
}

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<N-1;i++){
    int64_t A,B;
    scanf("%I64d %I64d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  scanf("%I64d",&S);
  S--;
  printf("%I64d\n",dfs(S,S).first*2);
  return 0;
}