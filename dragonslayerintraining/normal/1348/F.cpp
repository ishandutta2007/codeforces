#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
     
int as[200005];
int bs[200005];
int N;
     
std::set<std::pair<int,int> > buckets[200005];
int next[200005];
int prev[200005];
     
std::vector<std::pair<int,int> > start[200005];
int ans[200005];
int where[200005];
     
int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d %d",&as[i],&bs[i]);
    buckets[as[i]].insert({bs[i],i});
  }
  for(int i=0;i<=N+1;i++){
    next[i]=i+1;
    prev[i]=i-1;
  }
  int curr=1;
  while(curr<=N){
    if(buckets[curr].size()&&buckets[curr].begin()->first<next[curr]){
      int id=buckets[curr].begin()->second;
      buckets[curr].erase(buckets[curr].begin());
      ans[id]=curr;
      where[curr]=id;
      if(buckets[next[curr]].size()<buckets[curr].size()){
    	std::swap(buckets[next[curr]],buckets[curr]);
      }
      buckets[next[curr]].insert(buckets[curr].begin(),buckets[curr].end());
      buckets[curr].clear();
      prev[next[curr]]=prev[curr];
      next[prev[curr]]=next[curr];
      curr=prev[curr];
    }else{
      curr=next[curr];
    }
  }
  for(int i=1;i<=N;i++){
    start[as[i]].push_back({bs[i],i});
  }
  std::set<std::pair<int,int> > active;
  for(int i=1;i<=N;i++){
    for(auto p:start[i]){
      active.insert(p);
    }
    ans[active.begin()->second]=i;
    where[i]=active.begin()->second;
    active.erase(active.begin());
  }
  for(int i=next[0];next[i]<=N;i=next[i]){
    int j=next[i];
    if(as[where[j]]<=ans[where[i]]&&ans[where[i]]<=bs[where[j]]&&
       as[where[i]]<=ans[where[j]]&&ans[where[j]]<=bs[where[i]]){
      printf("NO\n");
      for(int i=1;i<=N;i++){
    	printf("%d ",ans[i]);
      }
      printf("\n");
      std::swap(ans[where[i]],ans[where[j]]);
      for(int i=1;i<=N;i++){
    	printf("%d ",ans[i]);
      }
      printf("\n");
      return 0;
    }
  }
  printf("YES\n");
  for(int i=1;i<=N;i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
}