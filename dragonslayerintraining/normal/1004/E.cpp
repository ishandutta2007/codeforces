#include <cstdio>
#include <queue>
#include <cassert>
#include <cstdlib>

int adj[100005];
int len[100005];
int deg[100005];
int degcnt[100005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N-1;i++){
    int U,V,D;
    scanf("%d %d %d",&U,&V,&D);
    U--,V--;
    adj[U]^=V,adj[V]^=U;
    len[U]^=D,len[V]^=D;
    deg[U]++,deg[V]++;
  }
  std::priority_queue<std::pair<int,int> > frontier;
  for(int i=0;i<N;i++){
    degcnt[deg[i]]++;
    if(deg[i]==1){
      frontier.emplace(-len[i],i);
    }
  }
  int cost=0;
  while(!frontier.empty()){
    if(degcnt[0]+degcnt[1]+degcnt[2]==N&&degcnt[1]+degcnt[2]<=K){
      printf("%d\n",cost);
      exit(0);
    }
    int dst=-frontier.top().first;
    int node=frontier.top().second;
    frontier.pop();
    assert(cost<=dst);
    cost=dst;
    int other=adj[node];
    len[other]^=len[node];
    adj[other]^=node;
    
    degcnt[deg[other]]--;
    if(--deg[other]==1){
      frontier.emplace(-dst-len[other],other);
    }
    degcnt[deg[other]]++;
    
    degcnt[1]--;
    degcnt[0]++;
  }
  printf("%d\n",cost);
  return 0;
}