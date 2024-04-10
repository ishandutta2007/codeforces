#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>

std::vector<int> edges[1000];
std::vector<int> rev[1000];

int min[1000];
int max[1000];

int good[1000];

void dfs_fwd(int node){
  if(good[node]&1) return;
  good[node]|=1;
  for(int other:edges[node]){
    dfs_fwd(other);
  }
}

void dfs_bkwd(int node){
  if(good[node]&2) return;
  good[node]|=2;
  for(int other:rev[node]){
    dfs_bkwd(other);
  }
}


std::vector<std::tuple<int,int,int> > elist;

int dist[1000];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    rev[B].push_back(A);
    elist.emplace_back(A,B,2);
    elist.emplace_back(B,A,-1);
  }
  dfs_fwd(0);
  dfs_bkwd(N-1);
  std::fill(dist,dist+N,0);
  for(int i=0;i<N;i++){
    for(auto e:elist){
      int a=std::get<0>(e);
      int b=std::get<1>(e);
      int w=std::get<2>(e);
      if(good[a]==3&&good[b]==3){
	dist[b]=std::min(dist[b],dist[a]+w);
      }
    }
  }
  for(auto e:elist){
    int a=std::get<0>(e);
    int b=std::get<1>(e);
    int w=std::get<2>(e);
    if(good[a]==3&&good[b]==3){
      if(dist[b]>dist[a]+w){
	printf("No\n");
	return 0;
      }
    }
  }
  printf("Yes\n");
  for(int i=0;i<elist.size();i+=2){
    auto e=elist[i];
    int a=std::get<0>(e);
    int b=std::get<1>(e);
    int w=std::get<2>(e);
    if(good[a]==3&&good[b]==3){
      printf("%d\n",dist[b]-dist[a]);
    }else{
      printf("1\n");
    }
  }
  return 0;
}