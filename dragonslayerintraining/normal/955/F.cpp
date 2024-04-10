#include <cstdio>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <algorithm>
#include <stdint.h>

std::vector<int> edges[300000];

int parent[300000];
int dp[300000];
int64_t sum=0;
int subtree[300000];

void dfs_parent(int node,int par){
  parent[node]=par;
  dp[node]=1;
  subtree[node]=1;
  for(int child:edges[node]){
    if(child==par) continue;
    dfs_parent(child,node);
    dp[node]=std::max(dp[node],dp[child]+1);
    subtree[node]=std::max(subtree[node],subtree[child]);
  }
  subtree[node]=std::max(subtree[node],dp[node]);
  sum+=subtree[node];
}

std::vector<std::array<int,30> > children;

std::list<int> buckets[300000];
std::list<int>::iterator nums[300000];
int critical[300000];

std::vector<std::pair<int,int> > shifts[300001];

void dfs_heap(int node){
  dp[node]=1;
  subtree[node]=1;
  std::vector<int> best;
  for(int child:edges[node]){
    if(child!=parent[node]){
      dfs_heap(child);
      best.push_back(dp[child]);
      children[node][dp[child]]++;
      subtree[node]=std::max(subtree[node],subtree[child]);
    }
  }
  std::sort(best.begin(),best.end());
  std::reverse(best.begin(),best.end());
  if(best.size()>=2){
    dp[node]=std::max(dp[node],best[1]+1);
  }
  for(int c:best){
    critical[node]+=(c>=(dp[node]-1));
  }
  nums[node]=buckets[critical[node]].insert(buckets[critical[node]].begin(),node);
  subtree[node]=std::max(subtree[node],dp[node]);
  sum+=subtree[node];
}

void set_critical(int node,int val){
  //printf("SETCRIT %d %d\n",node,val);
  buckets[critical[node]].erase(nums[node]);
  critical[node]=val;
  nums[node]=buckets[val].insert(buckets[val].begin(),node);
}

int64_t total=0;

int main(){
  int N;
  scanf("%d",&N);
  children.resize(N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  sum=0;
  dfs_parent(0,-1);
  total+=sum;
  /*
  printf("1:\n");
  for(int i=0;i<N;i++){
    printf("%d:%d\n",dp[i],subtree[i]);
  }
  */
  sum=0;
  dfs_heap(0);
  total+=sum;
  for(int i=0;i<N;i++){
    edges[i].clear();
  }
   /*
  printf("2:\n");
  for(int i=0;i<N;i++){
    printf("%d:%d\n",dp[i],subtree[i]);
  }
   */
  /*
  for(int i=0;i<N;i++){
    printf("Critical %d: %d\n",i,dp[i]);
  }
  */
  for(int k=3;k<=N;k++){
    std::queue<int> change;
    /*
    for(int i=0;i<50;i++){
      printf("BUCKET %d: %ld\n",i,buckets[i].size());
    }
    */
    for(int node:buckets[k-1]){
      change.push(node);
      //printf("CHANGE PUSH %d\n",node);
    }
    
    while(!change.empty()){
      int node=change.front();
      change.pop();
      //printf("CHANGE %d\n",node);
      if(critical[node]>=k||dp[node]==1) continue;
      if(parent[node]>=0){
	children[parent[node]][dp[node]]--;
	if(dp[node]>=dp[parent[node]]-1){
	  set_critical(parent[node],critical[parent[node]]-1);
	}
      }
      shifts[k].emplace_back(node,dp[node]);
      dp[node]--;
      set_critical(node,critical[node]+children[node][dp[node]-1]);
      if(parent[node]>=0){
	children[parent[node]][dp[node]]++;
	if(dp[node]>=dp[parent[node]]-1){
	  set_critical(parent[node],critical[parent[node]]+1);
	}
      }
      change.push(node);
      if(parent[node]>=0){
	change.push(parent[node]);
      }
    }
  }
  sum=N;
  for(int i=0;i<N;i++){
    buckets[i].clear();
  }
  children.clear();
  for(int k=N;k>2;k--){
    /*
    printf("%d:\n",k);
    for(int i=0;i<N;i++){
      printf("%d\n",dp[i]);
    }
    printf("SUM %ld\n",sum);
    */
    total+=sum;
    
    std::queue<std::pair<int,int> > events;
    std::reverse(shifts[k].begin(),shifts[k].end());
    for(std::pair<int,int> s:shifts[k]){
      events.push(s);
    }
    while(!events.empty()){
      int node=events.front().first;
      int set=events.front().second;
      events.pop();
      if(dp[node]<set){
	sum-=dp[node];
	dp[node]=set;
	sum+=dp[node];
	if(parent[node]>=0){
	  events.emplace(parent[node],set);
	}
      }
    }
  }
  printf("%I64d\n",total);
  return 0;
}