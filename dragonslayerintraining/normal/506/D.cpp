#include <cstdio>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <cassert>

const int CRIT=300;

std::vector<std::pair<int,int> > edges[100005];

std::map<std::pair<int,int>,int> rare;
std::vector<std::pair<int,int> > qs;
int common[100005];

std::vector<int> adj[100005];

int vis[100005];
std::vector<int> cc;

void dfs_cc(int node){
  vis[node]=1;
  cc.push_back(node);
  for(int child:adj[node]){
    if(!vis[child]){
      dfs_cc(child);
    }
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    A--,B--,C--;
    if(A>B) std::swap(A,B);
    edges[C].emplace_back(A,B);
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    if(U>V) std::swap(U,V);
    qs.emplace_back(U,V);
  }
  for(int c=0;c<M;c++){
    for(auto e:edges[c]){
      adj[e.first].push_back(e.second);
      adj[e.second].push_back(e.first);
    }
    for(auto e:edges[c]){
      if(!vis[e.first]){
	dfs_cc(e.first);
	assert(vis[e.second]);
	std::sort(cc.begin(),cc.end());
	if(cc.size()<CRIT){
	  for(int i=0;i<cc.size();i++){
	    for(int j=i+1;j<cc.size();j++){
	      rare[std::make_pair(cc[i],cc[j])]++;
	    }
	  }
	}else{
	  for(int i=0;i<Q;i++){
	    if(vis[qs[i].first]==1&&vis[qs[i].second]==1){
	      common[i]++;
	    }
	  }
	}
	for(int x:cc){
	  vis[x]=2;
	}
	cc.clear();
      }
    }
    for(auto e:edges[c]){
      vis[e.first]=vis[e.second]=0;
      adj[e.first].clear();
      adj[e.second].clear();
    }
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",common[i]+rare[qs[i]]);
  }
  return 0;
}