#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>

int best=0;

std::vector<int> edges[100005];
std::array<int,5> dp[100005];

void dfs(int node,int parent){
  auto& s=dp[node];
  s={0,0,0,0,0};
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
    const auto& t=dp[child];
    int x=std::max(t[0],t[1]);
    int y=std::max(x,t[3]);
    s={s[0]+1,
       std::max(s[1]+1,s[0]+y),
       std::max(s[2]+1,s[1]+y),
       std::max(s[3],1+x),
       std::max(s[4],s[3]+x)};
  }
  best=std::max(best,s[2]+(parent!=-1));  
  best=std::max(best,s[4]);  
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(0,-1);
  printf("%d\n",best);
}