#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int> > edges;

std::vector<int> adj[100000];

int pre[100000];
int low[100000];
int pre_max=1;

bool art[100000];
int hit[100000];

int vlvl=1;

int vis[100000];
bool vise[100000];

std::vector<std::pair<int,int> > treee[100000];
std::vector<std::pair<int,int> > backe[100000];

void dfs0(int node){
  //printf("DFS(%d)\n",node+1);
  if(pre[node]) return;
  pre[node]=pre_max++;
  for(int e:adj[node]){
    if(vise[e]) continue;
    vise[e]=true;
    int other=node^edges[e].first^edges[e].second;
    if(pre[other]){
      //printf("BACK(%d)\n",e+1);
      backe[node].emplace_back(other,e);
    }else{
      //printf("TREE(%d)\n",e+1);
      treee[node].emplace_back(other,e);
      dfs0(other);
    }
  }
}

void dfs1(int node){
  if(vis[node]>=vlvl) return;
  vis[node]=vlvl;
  low[node]=pre[node];
  for(auto pair:treee[node]){
    int other=pair.first;
    dfs1(other);
    low[node]=std::min(low[node],low[other]);
    if(low[other]>=pre[node]){
      art[pair.second]=true;
    }
  }
  for(auto pair:backe[node]){
    int other=pair.first;
    low[node]=std::min(low[node],pre[other]);
  }
}

std::vector<std::pair<int,std::vector<int> > > stks;
std::vector<int> good;

void dfs2(int node){
  if(vis[node]>=vlvl) return;
  vis[node]=vlvl;
  for(auto pair:treee[node]){
    int e=pair.second;
    if(art[e]) stks.emplace_back();
    int other=pair.first;
    stks.back().second.push_back(e);
    dfs2(other);
    if(art[e]){
      //printf("AT %d\n",node+1);
      //printf("FIRST=%d\n",stks.back().first);
      if(stks.back().first==1){
	for(int e2:stks.back().second){
	  good.push_back(e2);
	}
      }
      stks.pop_back();
    }
  }
  for(auto pair:backe[node]){
    stks.back().second.push_back(pair.second);
    stks.back().first++;
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(i);
    adj[V].push_back(i);
    edges.emplace_back(U,V);
  }
  for(int i=0;i<N;i++){
    dfs0(i);
  }
  vlvl++;
  for(int i=0;i<N;i++){
    dfs1(i);
  }
  /*
  for(int e=0;e<M;e++){
    printf("%d\n",art[e]);
  }
  */
  vlvl++;
  for(int i=0;i<N;i++){
    dfs2(i);
  }
  std::sort(good.begin(),good.end());
  printf("%d\n",(int)good.size());
  bool first=true;
  for(int e:good){
    if(first){first=false;}else{printf(" ");}
    printf("%d",e+1);
  }
  printf("\n");
  return 0;
}