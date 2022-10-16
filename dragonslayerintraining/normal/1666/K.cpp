#include <cstdio>
#include <queue>

using ll = long long;

const ll INF=1e15+7;

const int MAXE=4010;
const int MAXV=2010;

int elist[MAXE*2];
ll cap[MAXE*2];
int head[MAXV];
int next[MAXE*2];
int dist[MAXV];
int curr[MAXV];
int tot=0;

int N;

int src(){return N*2;}
int snk(){return N*2+1;}
int num_vertices(){return N*2+2;}

void add_he(int x,ll c){
  elist[tot]=x;
  cap[tot]=c;
  next[tot]=head[x];
  head[x]=tot++;
}

void add_dedge(int x,int y,ll c){
  add_he(x,c);
  add_he(y,0);
}

void add_uedge(int x,int y,ll c){
  add_he(x,c);
  add_he(y,c);
}

bool bfs(){
  std::fill(dist,dist+num_vertices(),-1);
  std::queue<int> q;
  dist[src()]=0;
  q.push(src());
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(int e=head[x];e!=-1;e=next[e]){
      if(cap[e]>0){
	int y=elist[e^1];
	if(dist[y]==-1){
	  dist[y]=dist[x]+1;
	  q.push(y);
	}
      }
    }
  }
  return dist[snk()]!=-1;
}

ll dfs(int x,ll f){
  if(x==snk()) return f;
  for(int& e=curr[x];e!=-1;e=next[e]){
    int y=elist[e^1];
    if(cap[e]>0&&dist[y]==dist[x]+1){
      ll aug=dfs(y,std::min(cap[e],f));
      if(aug>0){
	cap[e]-=aug;
	cap[e^1]+=aug;
	return aug;
      }
    }
  }
  return 0;
}

ll dinitz(){
  ll total_flow=0;
  while(bfs()){
    for(int i=0;i<num_vertices();i++){
      curr[i]=head[i];
    }
    while(true){
      ll aug=dfs(src(),INF);
      total_flow+=aug;
      if(aug==0) break;
    }
  }
  return total_flow;
}

int main(){
  int M;
  scanf("%d %d",&N,&M);
  int A,B;
  scanf("%d %d",&A,&B);
  A--,B--;
  std::fill(head,head+num_vertices(),-1);
  for(int i=0;i<M;i++){
    int U,V,L;
    scanf("%d %d %d",&U,&V,&L);
    U--,V--;
    add_uedge(U,V+N,L);
    add_uedge(V,U+N,L);
  }
  add_dedge(src(),A,INF);
  add_dedge(src(),B+N,INF);
  add_dedge(B,snk(),INF);
  add_dedge(A+N,snk(),INF);
  printf("%lld\n",dinitz());
  for(int i=0;i<N;i++){
    printf("%c","BCA"[(dist[i]!=-1)+(dist[i+N]==-1)]);
  }
  printf("\n");
}