#include <cstdio>
#include <stdint.h>
#include <vector>
#include <map>
#include <algorithm>

const int MOD=1e9+7;

int64_t xs[100005];

std::vector<int> edges[100005];

int64_t ans;

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

void dfs(int node,int parent,const std::map<int64_t,int>& cnts){
  std::map<int64_t,int> here;
  for(auto it:cnts){
    here[gcd(it.first,xs[node])]+=it.second;
  }
  here[xs[node]]++;
  for(auto it:here){
    ans=(ans+it.first*it.second)%MOD;
  }
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node,here);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%I64d",&xs[i]);
  }
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(0,0,{});
  printf("%I64d\n",ans);
}