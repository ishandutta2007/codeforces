#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>

int N;
int uf[100*100];
int miniuf[100];

int find(int* uf,int a){
  return (a==uf[a])?a:(uf[a]=find(uf,uf[a]));
}

int id(int r,int c){
  return r*N+c;
}

char eq[100][100][100];

int dist[100][100];

bool check(const std::vector<std::pair<int,int> >& edges){
  //fprintf(stderr,"CHECK %d==%d-1\n",(int)edges.size(),N);
  if(edges.size()!=N-1) return false;
  std::iota(miniuf,miniuf+N,0);
  for(auto e:edges){
    int x=find(miniuf,e.first);
    int y=find(miniuf,e.second);
    if(x==y) return false;
    miniuf[x]=y;
  }
  std::vector<std::vector<int> > adj(N);
  for(const auto& [x,y]:edges){
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int s=0;s<N;s++){
    std::queue<int> q;
    std::fill(dist[s],dist[s]+N,-1);
    dist[s][s]=0;
    q.push(s);
    while(!q.empty()){
      int x=q.front();
      q.pop();
      for(int y:adj[x]){
	if(dist[s][y]==-1){
	  dist[s][y]=dist[s][x]+1;
	  q.push(y);
	}
      }
    }
  }
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      for(int k=0;k<N;k++){
	if((eq[i][j][k]=='1')!=(dist[i][k]==dist[j][k])){
	  return false;
	}
      }
    }
  }
  return true;
}

void solve(){
  scanf("%d",&N);
  std::iota(uf,uf+N*N,0);
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      uf[find(uf,id(i,j))]=find(uf,id(j,i));
      scanf("%s",eq[i][j]);
      for(int k=0;k<N;k++){
	if(eq[i][j][k]=='1'){
	  uf[find(uf,id(i,k))]=find(uf,id(j,k));
	}
      }
    }
  }
  std::map<int,std::vector<std::pair<int,int> > > edges;
  for(int r=0;r<N;r++){
    for(int c=r+1;c<N;c++){
      edges[find(uf,id(r,c))].push_back({r,c});
    }
  }
  for(const auto& it:edges){
    if(check(it.second)){
      printf("Yes\n");
      for(auto e:it.second){
	printf("%d %d\n",e.first+1,e.second+1);
      }
      return;
    }
  }
  printf("No\n");
}


int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}