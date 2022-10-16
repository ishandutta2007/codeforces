#include <cstdio>
#include <cmath>
#include <vector>
#include <cassert>

const int BLOCK=400;
const bool debug=false;

int parent[100005];
std::vector<int> children[100005];
int crit[100005];
bool away[100005];//as used by data structure
bool away2[100005];//actual away
int burden[100005];//number in subtree on vacation
int N;

bool active[100005];
int shrink[100005];
int shrink_cnt=0;
int shrink_parent[BLOCK*2];
int shrink_delta[BLOCK*2][BLOCK*2];
int shrink_delta_i[BLOCK*2];

int qs[100005];
int ts[100005];
int ans=0;

int dfs_induce(int node){
  int cnt=0;
  for(int child:children[node]){
    cnt+=dfs_induce(child);
  }
  if(cnt>=2) active[node]=true;
  return cnt||active[node];
}

void dfs_shrink(int node){
  shrink[node]=-1;
  if(active[node]){
    shrink[node]=shrink_cnt++;
  }
  for(int child:children[node]){
    dfs_shrink(child);
    if(active[node]){
      if(shrink[child]!=-1){
	shrink_parent[shrink[child]]=node;
      }
    }else if(shrink[child]!=-1){
      assert(shrink[node]==-1);
      shrink[node]=shrink[child];
    }
  }
}

void dfs_away(int node){
  burden[node]=away[node];
  for(int child:children[node]){
    dfs_away(child);
    burden[node]+=burden[child];
  }
}

void dfs_add(int node){
  if(!active[node]&&!away[node]){
    int gap=crit[node]-burden[node];
    if(gap<0){
      ans++;
    }else if(gap<shrink_cnt&&shrink[node]!=-1){
      if(debug) printf("shrink_delta[shrink[%d]=%d][%d]++\n",node,shrink[node],gap);
      shrink_delta[shrink[node]][gap]++;
    }
  }
  for(int child:children[node]){
    dfs_add(child);
  }
}

void deactivate(int node){
  ans-=(burden[node]>crit[node]);
}

void activate(int node){
  ans+=(burden[node]>crit[node]);
}

void update_leave(int node){
  if(debug) printf("%d is leaving\n",node);
  deactivate(node);
  away[node]=true;
  for(;node!=-1;node=shrink_parent[shrink[node]]){
    assert(shrink[node]!=-1);
    if(debug) printf("  inform %d: displeased+=%d\n",node,shrink_delta[shrink[node]][shrink_delta_i[shrink[node]]]);
    ans+=shrink_delta[shrink[node]][shrink_delta_i[shrink[node]]++];
    if(!away[node]){
      deactivate(node);
    }
    burden[node]++;
    if(!away[node]){
      activate(node);
    }
  }
}

void update_enter(int node){
  if(debug) printf("%d is entering\n",node);
  activate(node);
  away[node]=false;
  for(;node!=-1;node=shrink_parent[shrink[node]]){
    assert(shrink[node]!=-1);
    ans-=shrink_delta[shrink[node]][--shrink_delta_i[shrink[node]]];
    if(debug) printf("  inform %d: displeased-=%d\n",node,shrink_delta[shrink[node]][shrink_delta_i[shrink[node]]]);
    if(!away[node]){
      deactivate(node);
    }
    burden[node]--;
    if(!away[node]){
      activate(node);
    }
  }
}

void handle_queries(int l,int r){
  if(debug) printf("handle_queries[%d,%d)\n",l,r);
  std::fill(active,active+N,false);
  for(int i=l;i<r;i++){
    active[qs[i]]=true;
  }
  dfs_induce(0);
  for(int i=0;i<N;i++){
    if(active[i]){
      away[i]=false;
    }
  }
  if(debug){
    for(int i=0;i<N;i++){
      printf("active[%d]=%d\n",i,active[i]);
    }
  }
  shrink_cnt=0;
  dfs_shrink(0);
  assert(shrink[0]!=-1);
  shrink_parent[shrink[0]]=-1;
  std::fill(shrink_delta_i,shrink_delta_i+shrink_cnt,0);
  for(int i=0;i<shrink_cnt;i++){
    std::fill(shrink_delta[i],shrink_delta[i]+shrink_cnt,0);
  }
  if(debug){
    for(int i=0;i<N;i++){
      printf("shrink[%d]=%d\n",i,shrink[i]);
    }
    for(int i=0;i<N;i++){
      if(active[i]){
	printf("parent*[%d]=%d\n",i,shrink_parent[shrink[i]]);
      }
    }
  }
  dfs_away(0);
  ans=0;
  dfs_add(0);
  for(int i=0;i<N;i++){
    if(active[i]){
      activate(i);
    }
  }
  if(debug){
    for(int i=0;i<N;i++){
      printf("crit0[%d]=%d, burden0[%d]=%d\n",i,crit[i],i,burden[i]);
    }
  }
  for(int i=0;i<N;i++){
    if(active[i]&&away2[i]){
      update_leave(i);
    }
  }
  assert(std::equal(away,away+N,away2));
  if(debug){
    for(int i=0;i<N;i++){
      printf("crit[%d]=%d, burden[%d]=%d\n",i,crit[i],i,burden[i]);
    }
  }
  for(int i=l;i<r;i++){
    if(ts[i]==1){
      update_leave(qs[i]);
      away2[qs[i]]=true;
    }else{
      update_enter(qs[i]);
      away2[qs[i]]=false;
    }
    printf("%d\n",ans);
  }
}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<N;i++){
    scanf("%d",&parent[i]);
    parent[i]--;
    children[parent[i]].push_back(i);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&crit[i]);
  }
  for(int i=0;i<Q;i++){
    scanf("%d",&qs[i]);
    if(qs[i]>0){
      qs[i]=qs[i]-1;
      ts[i]=1;
    }else{
      qs[i]=-qs[i]-1;
      ts[i]=-1;
    }
  }
  for(int i=0;i<Q;i+=BLOCK){
    handle_queries(i,std::min(Q,i+BLOCK));
  }
  return 0;
}