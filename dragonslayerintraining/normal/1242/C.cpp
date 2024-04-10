#include <cstdio>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stdint.h>

std::map<int64_t,int64_t> where;
std::vector<int64_t> box[16];
long long box_sum[16];

std::map<int64_t,std::vector<int64_t>> from;
std::map<int64_t,int64_t> to;

std::map<int64_t,int64_t> vis;
std::vector<int64_t> cycle;
bool dfs(int64_t x){
  if(vis[x]==2) return false;
  if(vis[x]==1){
    cycle.erase(cycle.begin(),std::find(cycle.begin(),cycle.end(),x));
    return true;
  }
  vis[x]=1;
  cycle.push_back(x);
  for(int64_t y:from[x]){
    if(dfs(y)){
      vis[x]=2;
      return true;
    }
  }
  cycle.pop_back();
  vis[x]=2;
  return false;
}

std::map<int64_t,std::vector<int64_t> > single;

bool dp[1<<15];

int64_t cs[16];
int64_t ps[16];

void recover(int64_t mask){
  if(single.count(mask)){
    std::vector<int64_t> cycle=single[mask];
    for(int64_t y:cycle){
      int64_t x=to[y];
      int64_t i=where[x];
      cs[i]=x;
      ps[i]=where[y];
    }
    return;
  }
  for(int64_t sub=(mask-1)&mask;sub;sub=(sub-1)&mask){
    int64_t rest=mask&~sub;
    if(dp[sub]&&dp[rest]){
      recover(sub);
      recover(rest);
      return;
    }
  }
  assert(0); 
}

int main(){
  int64_t K;
  scanf("%lld",&K);
  long long total_sum=0;
  for(int64_t i=0;i<K;i++){
    int64_t N;
    scanf("%lld",&N);
    for(int64_t j=0;j<N;j++){
      int64_t A;
      scanf("%lld",&A);
      box[i].push_back(A);
      box_sum[i]+=A;
      total_sum+=A;
      where[A]=i;
    }
  }
  long long target=total_sum/K;
  for(auto it:where){
    int64_t i=it.second;
    int64_t x=it.first;
    int64_t y=x+target-box_sum[i];
    if(where.count(y)){
      to[x]=y;
      from[y].push_back(x);
    }
  }
  for(int64_t i=0;i<K;i++){
    for(int64_t x:box[i]){
      if(dfs(x)){
	int64_t mask=0;
	bool bad=false;
	for(int64_t v:cycle){
	  if(mask&(1<<where[v])){
	    bad=true;
	    break;
	  }
	  mask|=(1<<where[v]);
	}
	if(!bad){
	  single[mask]=cycle;
	}
	cycle.clear();
      }
    }
  }
  for(int64_t mask=0;mask<(1<<K);mask++){
    if(single.count(mask)){
      dp[mask]=true;
      continue;
    }
    for(int64_t sub=(mask-1)&mask;sub;sub=(sub-1)&mask){
      int64_t rest=mask&~sub;
      dp[mask]|=dp[sub]&dp[rest];
    }
  }
  if(!dp[(1<<K)-1]){
    printf("No\n");
    return 0;
  }
  recover((1<<K)-1);
  printf("Yes\n");
  for(int64_t i=0;i<K;i++){
    printf("%lld %lld\n",cs[i],ps[i]+1);
  }
}