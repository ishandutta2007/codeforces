#include <iostream>
#include <vector>
#include <queue>

struct cedge{
  int other;
  long long len;
  cedge(int other,long long len):other(other),len(len){
  }
};
struct cpath{
  int node,prev;
  long long len;
  cpath(int node,int prev,long long len):node(node),prev(prev),len(len){
  }
  bool operator<(struct cpath other)const{
    if(len!=other.len){return len>other.len;}
    if(node!=other.node){return node<other.node;}
    if(prev!=other.prev){return prev<other.prev;}
    return false;
  }
};

std::vector<struct cedge> edges[100000];

long long dist[100000];
int prev[100000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int A,B,L;
    std::cin>>A>>B>>L;
    A--;B--;
    edges[A].push_back(cedge(B,L));
    edges[B].push_back(cedge(A,L));
  }
  for(int i=0;i<N;i++){
    dist[i]=1e18;
    prev[i]=-1;
  }
  std::priority_queue<struct cpath> frontier;
  frontier.push(cpath(N-1,-1,0));
  while(!frontier.empty()){
    int node=frontier.top().node;
    int prv=frontier.top().prev;
    long long len=frontier.top().len;
    frontier.pop();
    if(len>=dist[node]){
      continue;
    }
    dist[node]=len;
    prev[node]=prv;
    for(int i=0;i<edges[node].size();i++){
      frontier.push(cpath(edges[node][i].other,node,len+edges[node][i].len));
    }
  }
  if(dist[0]==1e18){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(int node=0;node>=0;node=prev[node]){
    if(node!=0){
      std::cout<<" ";
    }
    std::cout<<node+1;
  }
  std::cout<<std::endl;
  return 0;
}