#include <cstdio>
#include <vector>
#include <array>

std::vector<std::array<int,2> > elist;
std::vector<int> before[100005];
bool vis[100005];
int rank[100005];
int rank_max=0;

void dfs(int node){
  if(vis[node]) return;
  vis[node]=true;
  for(int v:before[node]){
    dfs(v);
  }
  rank[node]=rank_max++;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    before[V].push_back(U);
    elist.push_back({U,V});
  }
  for(int i=0;i<N;i++){
    dfs(i);
  }
  int cnt=0;
  for(int i=0;i<M;i++){
    int U=elist[i][0],V=elist[i][1];
    if(rank[U]+1==rank[V]){
      if(++cnt==N-1){
	printf("%d\n",i+1);
	return 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}