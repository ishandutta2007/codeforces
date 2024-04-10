#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>

const int INF=1e9+7;

int dist[300000];
int prev[300000];
std::vector<int> edges[300000];

bool vis[300000];

std::set<std::pair<int,int> > conn;
int N;

void grow(int node){
  std::vector<int> complete;
  complete.push_back(node);
  vis[node]=true;
  for(int i=0;i<complete.size();i++){
    for(int other:edges[complete[i]]){
      if(other==0) continue;
      if(vis[other]) continue;
      for(int j=0;j<complete.size();j++){
	if(!conn.count(std::make_pair(other,complete[j]))){
	  printf("5\n");
	  printf("%d %d %d %d %d %d\n",1,other+1,complete[i]+1,complete[j]+1,other+1,N);
	  exit(0);
	}
      }
      complete.push_back(other);
      vis[other]=true;
    }
  }
}

void basic(){
  std::vector<int> path;
  for(int node=N-1;node!=0;node=prev[node]){
    path.push_back(node);
  }
  printf("%d\n",(int)path.size());
  path.push_back(0);
  std::reverse(path.begin(),path.end());
  for(int i=0;i<path.size();i++){
    if(i) printf(" ");
    printf("%d",path[i]+1);
  }
  printf("\n");
  exit(0);
}

void bfs(){
  std::fill(dist,dist+N,INF);
  std::vector<int> curr;
  int d=0;
  curr.push_back(0);
  dist[0]=0;
  while(!curr.empty()){
    std::vector<int> next;
    for(int node:curr){
      for(int other:edges[node]){
	if(dist[other]==INF){
	  dist[other]=d+1;
	  prev[other]=node;
	  next.push_back(other);
	}
      }
    }
    std::swap(curr,next);
    d++;
  }
}

int main(){
  int M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
    conn.emplace(U,V);
    conn.emplace(V,U);
  }
  bfs();
  int four=-1;
  for(int i=0;i<N;i++){
    if(dist[i]==2){
      four=i;
    }
  }
  if(dist[N-1]<4){
    basic();
  }
  if(four>=0){
    printf("4\n");
    printf("%d %d %d %d %d\n",1,prev[four]+1,four+1,1,N);
    return 0;
  }
  for(int i=0;i<N;i++){
    if(dist[i]==1){
      if(!vis[i]){
	grow(i);
      }
    }
  }
  if(dist[N-1]<INF){
    basic();
  }
  printf("-1\n");
  return 0;
}