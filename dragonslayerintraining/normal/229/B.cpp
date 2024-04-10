#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdint.h>

struct cedge{
  int64_t other,len;
  cedge(int64_t other,int64_t len):other(other),len(len){
  }
};

struct cpath{
  int64_t node,len;
  cpath(int64_t node,int64_t len):node(node),len(len){
  }
  bool operator<(struct cpath other)const{
    return len>other.len;
  }
};

std::vector<struct cedge> edges[100000];
std::vector<int64_t> travel[100000];
int64_t dist[100000];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    A--,B--;
    edges[A].push_back(cedge(B,C));
    edges[B].push_back(cedge(A,C));
  }
  for(int i=0;i<N;i++){
    int K;
    scanf("%d",&K);
    for(int j=0;j<K;j++){
      int T;
      scanf("%d",&T);
      travel[i].push_back(T);
    }
  }
  for(int i=0;i<N;i++){
    dist[i]=1e10;
  }
  std::priority_queue<struct cpath> frontier;
  frontier.push(cpath(0,0));
  while(!frontier.empty()){
    struct cpath path=frontier.top();
    //std::cout<<path.node<<"\t"<<path.len<<std::endl;
    frontier.pop();
    if(dist[path.node]<=path.len){
      continue;
    }
    dist[path.node]=path.len;
    for(int i=0;i<travel[path.node].size();i++){
      if(travel[path.node][i]==path.len){
	path.len++;
      }
    }
    for(struct cedge edge:edges[path.node]){
      frontier.push(cpath(edge.other,path.len+edge.len));
    }
  }
  if(dist[N-1]==1e10){
    printf("-1\n");
  }else{
    printf("%d\n",int(dist[N-1]));
  }
  return 0;
}