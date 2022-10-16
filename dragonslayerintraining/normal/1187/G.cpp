#include <cstdio>
#include <algorithm>
#include <queue>
#include <cassert>

const int INF=1e9+7;

int N,M,K,C,D;
const int T=100;
int SRC,SNK;

int head[5005];
int prev[5005*500];
int elist[5005*500];
int cap[5005*500];
int cost[5005*500];

int graph_size=0;

int dist[5005];
int from[5005];

void add(int x,int c,int w){
  assert(graph_size<5005*500);
  assert(x>=0&&x<N*T+2);
  cap[graph_size]=c;
  cost[graph_size]=w;
  elist[graph_size]=x;
  prev[graph_size]=head[x];
  head[x]=graph_size++;
}

void add(int x,int y,int c,int w){
  add(x,c,w);
  add(y,0,-w);
  //printf("edge %d=>%d cap=%d cost=%d\n",x,y,c,w);
}


int main(){
  scanf("%d %d %d %d %d",&N,&M,&K,&C,&D);  
  SRC=N*T,SNK=N*T+1;
  std::fill(head,head+N*T+2,-1);
  for(int i=0;i<K;i++){
    int A;
    scanf("%d",&A);
    A--;
    add(SRC,A,1,0);
  }
  for(int i=0;i<N;i++){
    for(int t=0;t<T-1;t++){
      add(i+t*N,i+(t+1)*N,INF,C);
    }
  }
  for(int t=0;t<T-1;t++){
    add(t*N,SNK,INF,0);
  }
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    for(int t=0;t<T-1;t++){
      for(int k=50;k>=0;k--){
	add(X+t*N,Y+(t+1)*N,1,C+D*(2*k+1));
	add(Y+t*N,X+(t+1)*N,1,C+D*(2*k+1));
      }
    }
  }
  int total_flow=0,total_cost=0;
  while(true){
    std::fill(dist,dist+N*T+2,INF);
    std::queue<int> q;
    dist[SRC]=0;
    from[SRC]=-1;
    q.push(SRC);
    while(!q.empty()){
      int node=q.front();
      q.pop();
      assert(node>=0&&node<N*T+2);
      for(int e=head[node];e!=-1;e=prev[e]){
	int child=elist[e^1];
	assert(node!=child);
	if(cap[e]&&dist[child]>dist[node]+cost[e]){
	  dist[child]=dist[node]+cost[e];
	  from[child]=e;
	  q.push(child);
	}
      }
    }
    if(dist[SNK]==INF) break;
    for(int e=from[SNK];e!=-1;e=from[elist[e]]){
      //printf("aug %d=>%d (cost %d)\n",elist[e^1],elist[e],cost[e]);
      cap[e]--;
      cap[e^1]++;
      total_cost+=cost[e];
    }
    total_flow++;
  }
  printf("%d\n",total_cost);
  assert(total_flow==K);
}