#include <cstdio>
#include <vector>
#include <map>
#include <array>
#include <algorithm>

std::vector<std::vector<int> > edges;

bool vis[100005];

void dfs_post(int x,std::vector<int>& post){
  if(vis[x]) return;
  vis[x]=true;
  for(int y:edges[x]){
    dfs_post(y,post);
  }
  post.push_back(x);
}

void solve(){
  int N;
  scanf("%d",&N);
  edges.clear();
  edges.resize(N-2);
  std::map<std::pair<int,int>,int> prev;
  for(int i=0;i<N-2;i++){
    std::array<int,3> ps;
    scanf("%d %d %d",&ps[0],&ps[1],&ps[2]);
    for(int i=0;i<3;i++){
      ps[i]--;
    }
    std::sort(ps.begin(),ps.begin()+3);
    auto add=[&](int a,int b){
      std::pair<int,int> e{a,b};
      if(prev.count(e)){
	edges[i].push_back(prev[e]);
	edges[prev[e]].push_back(i);
	prev.erase(e);
      }else{
	prev[e]=i;
      }
    };
    add(ps[0],ps[1]);
    add(ps[0],ps[2]);
    add(ps[1],ps[2]);
  }
  std::vector<int> ps,qs;
  std::fill(vis,vis+N-2,false);
  dfs_post(0,qs);
  edges.clear();
  edges.resize(N);
  for(auto it:prev){
    edges[it.first.first].push_back(it.first.second);
    edges[it.first.second].push_back(it.first.first);
  }
  std::fill(vis,vis+N,false);
  dfs_post(0,ps);
  for(int i=0;i<N;i++){
    printf("%d ",ps[i]+1);
  }
  printf("\n");
  for(int i=0;i<N-2;i++){
    printf("%d ",qs[i]+1);
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}