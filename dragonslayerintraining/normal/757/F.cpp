#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#include <stdint.h>

const int64_t INF=1e18;

//algorithm by T.Lengauer and R.E.Tarjan.

//Note: vertices are 1-indexed
class DominatorTree{
  int64_t N;
  std::vector<std::vector<int64_t> > succ;
  std::vector<std::vector<int64_t> > pred;
  std::vector<int64_t> parent;
  std::vector<int64_t> semi;
  std::vector<int64_t> vertex;
  std::vector<std::vector<int64_t> > bucket;
  std::vector<int64_t> dom;
  std::vector<int64_t> anc;
  std::vector<int64_t> label;

  void dfs(int64_t node){
    semi[node]=++N;
    vertex[N]=node;
    for(int64_t child:succ[node]){
      if(!semi[child]){
	parent[child]=node;
	dfs(child);
      }
      pred[child].push_back(node);
    }
  }

  void compress(int64_t node){
    if(anc[anc[node]]){
      compress(anc[node]);
      if(semi[label[anc[node]]]<semi[label[node]]){
	label[node]=label[anc[node]];
      }
      anc[node]=anc[anc[node]];
    }
  }

  int64_t eval(int64_t node){
    if(!anc[node]) return node;
    compress(node);
    return label[node];
  }
  DominatorTree(const std::vector<std::vector<int64_t> >& adj,int64_t root):
    N(adj.size()),succ(adj),pred(N),parent(N),semi(N),vertex(N),bucket(N),dom(N),anc(N),label(N){
    std::iota(label.begin(),label.end(),0);
    N=0;
    dfs(root);
    for(int64_t i=N;i>=2;i--){
      int64_t node=vertex[i];
      for(int64_t from:pred[node]){
	int64_t u=eval(from);
	semi[node]=std::min(semi[node],semi[u]);
      }
      bucket[vertex[semi[node]]].push_back(node);
      anc[node]=parent[node];
      for(int64_t v:bucket[parent[node]]){
	int64_t u=eval(v);
	dom[v]=(semi[u]<semi[v])?u:parent[node];
      }
      bucket[parent[node]].clear();
    }
    for(int64_t i=2;i<=N;i++){
      int64_t node=vertex[i];
      if(dom[node]!=vertex[semi[node]]) dom[node]=dom[dom[node]];
    }
  }
public:
  static std::vector<int64_t> generate(const std::vector<std::vector<int64_t> >& adj,int64_t root){
    return DominatorTree(adj,root).dom;
  }
};

int64_t dist[200000];
int64_t size[200000];
int64_t S;
int64_t best=0;

void dfs(std::vector<std::vector<int64_t> >& adj,int64_t node){
  size[node]=1;
  for(int64_t child:adj[node]){
    dfs(adj,child);
    size[node]+=size[child];
  }
  if(node!=S) best=std::max(best,size[node]);
}

std::vector<std::tuple<int64_t,int64_t,int64_t> > edges;
int64_t N,M;

void shortest_paths(){
  std::vector<std::vector<std::pair<int64_t,int64_t> > > adj(N+1);
  for(auto e:edges){
    int64_t U=std::get<0>(e);
    int64_t V=std::get<1>(e);
    int64_t W=std::get<2>(e);
    adj[U].emplace_back(V,W);
    adj[V].emplace_back(U,W);
  }
  std::fill(dist,dist+N+1,INF);
  std::set<std::pair<int64_t,int64_t> > frontier;
  frontier.emplace(0,S);
  while(!frontier.empty()){
    int64_t dst=frontier.begin()->first;
    int64_t node=frontier.begin()->second;
    frontier.erase(frontier.begin());
    if(dst>=dist[node]) continue;
    dist[node]=dst;
    for(auto e:adj[node]){
      frontier.emplace(dst+e.second,e.first);
    }
  }
}

int main(){
  scanf("%I64d %I64d %I64d",&N,&M,&S);
  for(int64_t i=1;i<=M;i++){
    int64_t U,V,W;
    scanf("%I64d %I64d %I64d",&U,&V,&W);
    edges.emplace_back(U,V,W);
  }
  shortest_paths();
  std::vector<std::vector<int64_t> > adj(N+1);
  for(auto e:edges){
    int64_t U=std::get<0>(e);
    int64_t V=std::get<1>(e);
    int64_t W=std::get<2>(e);
    if(dist[U]+W==dist[V]){
      adj[U].push_back(V);
      //printf("%I64d => %I64d\n",U,V);
    }
    if(dist[V]+W==dist[U]){
      adj[V].push_back(U);
      //printf("%I64d => %I64d\n",V,U);
    }
  }
  std::vector<int64_t> dom=DominatorTree::generate(adj,S);
  adj.clear();
  adj.resize(N+1);
  for(int64_t i=1;i<=N;i++){
    if(i!=S) adj[dom[i]].push_back(i);
  }
  dfs(adj,S);
  printf("%I64d\n",best);
  return 0;
}