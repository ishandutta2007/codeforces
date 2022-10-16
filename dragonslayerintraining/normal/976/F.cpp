#include <cstdio>
#include <algorithm>
#include <vector>

int res[4002][4002];
int SRC,SNK;
int flow=0;

std::vector<std::pair<int,int> > elist;

std::vector<int> edges[4002];
int deg1[2000];
int deg2[2000];

bool vis[4002];

bool dfs(int node){
  if(node==SNK) return true;
  if(vis[node]) return false;
  vis[node]=true;
  for(int adj:edges[node]){
    if(res[node][adj]){
      if(dfs(adj)){
	res[node][adj]--;
	res[adj][node]++;
	return true;
      }
    }
  }
  return false;
}

std::vector<std::vector<int> > ans;

int main(){
  int N1,N2,M;
  scanf("%d %d %d",&N1,&N2,&M);
  SRC=N1+N2;
  SNK=N1+N2+1;
  for(int i=0;i<N1;i++){
    edges[SRC].push_back(i);
    edges[i].push_back(SRC);
  }
  for(int i=0;i<N2;i++){
    edges[SNK].push_back(N1+i);
    edges[N1+i].push_back(SNK);
  }
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    elist.emplace_back(U,V);
    edges[U].push_back(N1+V);
    edges[N1+V].push_back(U);
    res[U][N1+V]++;
    deg1[U]++;
    deg2[V]++;
  }
  int mindeg=1e9;
  for(int i=0;i<N1;i++){
    mindeg=std::min(mindeg,deg1[i]);
  }
  for(int i=0;i<N2;i++){
    mindeg=std::min(mindeg,deg2[i]);
  }
  for(int i=0;i<N1;i++){
    res[SRC][i]=deg1[i]-mindeg;
  }
  for(int i=0;i<N2;i++){
    res[N1+i][SNK]=deg2[i]-mindeg;
  }
  for(int k=0;k<=mindeg;k++){
    while(true){
      std::fill(vis,vis+N1+N2+2,false);
      if(!dfs(SRC)) break;
      flow++;
    }
    std::vector<int> ids;
    for(int i=0;i<elist.size();i++){
      auto e=elist[i];
      if(res[e.first][N1+e.second]){
	res[e.first][N1+e.second]--;
	ids.push_back(i);
      }
    }
    ans.emplace_back(ids);
    for(int i:ids){
      auto e=elist[i];
      res[e.first][N1+e.second]++;
    }
    for(int i=0;i<N1;i++){
      res[SRC][i]++;
    }
    for(int i=0;i<N2;i++){
      res[N1+i][SNK]++;
    }
  }
  std::reverse(ans.begin(),ans.end());
  for(auto a:ans){
    printf("%d",(int)a.size());
    for(int i:a){
      printf(" %d",i+1);
    }
    printf("\n");
  }
  return 0;
}