#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>

int elist[200000];
int ws[100000];
int bad[100000];

std::vector<int> adj[100000];
std::vector<int> treee[100000];
std::vector<int> backe[100000];
int uf[100000];
int vis[100000];
int evis[100000];
int pre[100000];
int low[100000];
int bcc[100000];
int size[100000];
int nbccs=0;
int id=0;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void dfs0(int node,int parent,int t){
  if(vis[node]==t) return;
  vis[node]=t;
  low[node]=pre[node]=id++;
  for(int e:adj[node]){
    if(evis[e>>1]) continue;
    evis[e>>1]=true;
    int to=find(elist[e^1]);
    if(vis[to]<t){
      dfs0(to,node,t);
      treee[node].push_back(e);
    }else{
      backe[node].push_back(e);
    }
  }
  for(int e:treee[node]){
    int to=find(elist[e^1]);
    low[node]=std::min(low[node],low[to]);
  }
  for(int e:backe[node]){
    int to=find(elist[e^1]);
    low[node]=std::min(low[node],pre[to]);
  }
}

std::vector<int> stk;

void dfs1(int node,int parent,int t){
  if(vis[node]==t) return;
  vis[node]=t;
  for(int e:treee[node]){
    int to=find(elist[e^1]);
    if(low[to]>=pre[node]){
      stk.push_back(nbccs++);
    }
    dfs1(to,node,t);
    bcc[e>>1]=stk.back();
    size[stk.back()]++;
    if(low[to]>=pre[node]){
      stk.pop_back();
    }
  }
  for(int e:backe[node]){
    bcc[e>>1]=stk.back();
    size[stk.back()]++;
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N,0);
  std::map<int,std::vector<int> > sorted;
  for(int i=0;i<M;i++){
    scanf("%d %d %d",&elist[i*2],&elist[i*2+1],&ws[i]);
    elist[i*2]--;
    elist[i*2+1]--;
    sorted[ws[i]].push_back(i*2);
    sorted[ws[i]].push_back(i*2+1);
  }
  for(auto pair:sorted){
    for(int e:pair.second){
      if(find(elist[e])==find(elist[e^1])){
	bad[e>>1]=1;
      }else{
	adj[find(elist[e])].push_back(e);
      }
    }
    for(int e:pair.second){
      dfs0(find(elist[e]),find(elist[e]),pair.first*2);
    }
    for(int e:pair.second){
      dfs1(find(elist[e]),find(elist[e]),pair.first*2+1);
      assert(stk.empty());
    }
    for(int e:pair.second){
      adj[find(elist[e])].clear();
      treee[find(elist[e])].clear();
      backe[find(elist[e])].clear();
    }
    for(int e:pair.second){
      uf[find(elist[e])]=find(elist[e^1]);
    }
  }
  for(int i=0;i<M;i++){
    if(bad[i]){
      printf("none\n");
    }else if(size[bcc[i]]==1){
      printf("any\n");
    }else{
      printf("at least one\n");
    }
  }
  return 0;
}