#include <cstdio>
#include <queue>
#include <vector>
#include <stdint.h>

const int64_t INF=1e18;

struct Dinitz{
  int64_t N;
  int64_t SRC,SNK;
  std::vector<int64_t> elist;
  std::vector<int64_t> cap;
  std::vector<int64_t> next;
  std::vector<int64_t> head;
  std::vector<int64_t> curr;
  std::vector<int64_t> dist;
  int64_t flow;
  Dinitz(int64_t N,int64_t SRC,int64_t SNK):N(N),SRC(SRC),SNK(SNK),head(N,-1),curr(N),dist(N),flow(0){
  }
  void add_he(int64_t node,int64_t c){
    next.push_back(head[node]);
    cap.push_back(c);
    head[node]=elist.size();
    elist.push_back(node);
  }
  void add(int64_t from,int64_t to,int64_t c){
    add_he(from,c);
    add_he(to,0);
  }
  bool bfs(){
    std::fill(dist.begin(),dist.end(),INF);
    std::queue<int64_t> frontier;
    dist[SRC]=0;
    frontier.push(SRC);
    while(!frontier.empty()){
      int64_t node=frontier.front();
      frontier.pop();
      for(int64_t e=head[node];e!=-1;e=next[e]){
	if(cap[e]&&dist[elist[e^1]]==INF){
	  dist[elist[e^1]]=dist[node]+1;
	  frontier.push(elist[e^1]);
	}
      }
    }
    return dist[SNK]<INF;
  }
  int64_t dfs(int64_t node,int64_t lim){
    if(node==SNK){
      return lim;
    }
    int64_t &e=curr[node];
    for(;e!=-1;e=next[e]){
      if(dist[elist[e^1]]==dist[node]+1&&cap[e]){
	int64_t f=dfs(elist[e^1],std::min(lim,cap[e]));
	if(f){
	  cap[e]-=f;
	  cap[e^1]+=f;
	  return f;
	}
      }
    }
    return 0;
  }
  int64_t maxflow(){
    /*
    for(int64_t i=0;i<elist.size();i++){
      printf("CAP(%d)=%d\n",i,cap[i]);
    }
    */
    while(bfs()){
      std::copy(head.begin(),head.end(),curr.begin());
      int64_t inc=0;
      do{
	inc=dfs(SRC,INF);
	flow+=inc;
      }while(inc);
    }
    /*
    for(int64_t i=0;i<elist.size();i++){
      printf("CAP(%d)=%d\n",i,cap[i]);
    }
    */
    return flow;
  }
};

int64_t ps[100];
int64_t cs[103];
int64_t ls[100];

bool isprime[200001];

int main(){
  /*
  struct Dinitz dinitz(4,0,3);
  dinitz.add(0,1,5);
  dinitz.add(0,2,4);
  dinitz.add(1,2,3);
  dinitz.add(1,3,4);
  dinitz.add(2,3,5);
  printf("FLOW=%I64d\n",dinitz.maxflow());
  return 0;
  */
  std::fill(isprime+2,isprime+200001,true);
  for(int64_t i=2;i<=200000;i++){
    if(isprime[i]){
      for(int64_t j=i*2;j<=200000;j+=i){
	isprime[j]=false;
      }
    }
  }
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d %I64d %I64d",&ps[i],&cs[i],&ls[i]);
  }
  const int64_t SRC=N,SNK=N+1,ONE=N+2;
  cs[ONE]=1;
  std::vector<int64_t> even,odd;
  for(int64_t i=0;i<N;i++){
    if(cs[i]==1) continue;
    if(cs[i]%2==0){
      even.push_back(i);
    }else{
      odd.push_back(i);
    }
  }
  odd.push_back(ONE);
  int64_t low=0,high=N+1;
  while(high-low>1){
    int64_t total=0;
    int64_t mid=(low+high)/2;
    struct Dinitz dinitz(N+3,SRC,SNK);
    int64_t one=0;
    for(int64_t i=0;i<N;i++){
      if(ls[i]>mid) continue;
      if(cs[i]==1){
	one=std::max(one,ps[i]);
      }else if(cs[i]%2==0){
	dinitz.add(SRC,i,ps[i]);
	total+=ps[i];
      }else{
	dinitz.add(i,SNK,ps[i]);
	total+=ps[i];
      }
    }
    dinitz.add(ONE,SNK,one);
    total+=one;
    for(int64_t i:even){
      for(int64_t j:odd){
	if(isprime[cs[i]+cs[j]]){
	  dinitz.add(i,j,INF);
	}
      }
    }
    total-=dinitz.maxflow();
    //printf("level=%I64d flow=%I64d power=%I64d\n",mid,dinitz.maxflow(),total);
    if(total<K){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%I64d\n",(high<=N)?high:-1);
  return 0;
}