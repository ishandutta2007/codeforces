#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <stdint.h>

//Rake: (x,z),(y,z) => (x,z)
//Compress: (x,y),(y,z) => (x,z)

//b is above a
struct Node{
  enum Type{
    RAKE,COMPRESS,
  }type;
  int a,b;
}nodes[200005];
struct DP{
  int64_t len,amax,bmax,diam;
  DP(int64_t len,int64_t amax,int64_t bmax,int64_t diam):len(len),amax(amax),bmax(bmax),diam(diam){
  }
  DP(int64_t x):DP(x,x,x,x){
  }
  DP():DP(0){
  }
}values[200005];
int parent[200005];

DP combine(Node::Type type,DP x,DP y){
  switch(type){
  case Node::RAKE:
    return DP(x.len,
	      std::max(x.amax,x.len+y.bmax),
	      std::max(x.bmax,y.bmax),
	      std::max(x.bmax+y.bmax,std::max(x.diam,y.diam)));
  case Node::COMPRESS:
    return DP(x.len+y.len,
	      std::max(x.amax,x.len+y.amax),
	      std::max(y.bmax,y.len+x.bmax),
	      std::max(x.bmax+y.amax,std::max(x.diam,y.diam)));
  }
  assert(0);
}

int nodes_cnt=0;

int new_node(enum Node::Type type,int a,int b){
  //printf("new_node(%d,%d,%d)\n",(int)type,a,b);
  nodes[nodes_cnt].type=type;
  nodes[nodes_cnt].a=a;
  nodes[nodes_cnt].b=b;
  parent[a]=nodes_cnt;
  parent[b]=nodes_cnt;
  return nodes_cnt++;
}

int elist[200005];

std::vector<int> edges[200005];
int size[200005];
int64_t ws[200005];

void dfs_size(int node){
  size[node]=1;
  for(int e:edges[node]){
    int child=elist[e^1];
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),e^1));
    dfs_size(child);
    size[node]+=size[child];
  }
}

void dfs_hld(int node){
  for(int e:edges[node]){
    int child=elist[e^1];
    dfs_hld(child);
  }
  for(int& e:edges[node]){
    int child=elist[e^1];
    if(size[child]>size[elist[edges[node][0]^1]]){
      std::swap(e,edges[node][0]);
    }
  }
}

int reduce(enum Node::Type type,std::vector<int> roots){
  while(roots.size()>1){
    std::vector<int> next;
    for(int i=0;i<roots.size();i+=2){
      if(i+1<roots.size()){
	next.push_back(new_node(type,roots[i],roots[i+1]));
      }else{
	next.push_back(roots[i]);
      }
    }
    std::swap(next,roots);
  }
  return roots.front();
}

std::vector<int>* dfs_rc(int node){
  //printf("dfs_rc(%d)\n",node);
  if(edges[node].empty()) return new std::vector<int>();
  std::vector<int> branches;
  branches.push_back(edges[node][0]>>1);
  std::vector<int>* heavy=dfs_rc(elist[edges[node][0]^1]);
  for(int e:edges[node]){
    if(e==edges[node][0]) continue;
    int child=elist[e^1];
    std::vector<int>* path=dfs_rc(child);
    path->push_back(e>>1);
    branches.push_back(reduce(Node::COMPRESS,*path));
    delete path;
  }
  heavy->push_back(reduce(Node::RAKE,branches));
  return heavy;
}

int N;

void dump(int node){
  if(node<N-1){
    printf("%d",node+1);
  }else{
    if(nodes[node].type==Node::RAKE){
      printf("R(");
    }else{
      printf("C(");
    }
    dump(nodes[node].a);
    printf(",");
    dump(nodes[node].b);
    printf(")");
  }
}

void pull(int i){
  values[i]=combine(nodes[i].type,values[nodes[i].a],values[nodes[i].b]);
}

int main(){
  int64_t Q,W;
  scanf("%d %I64d %I64d",&N,&Q,&W);
  for(int i=0;i<N-1;i++){
    int64_t A,B,C;
    scanf("%I64d %I64d %I64d",&A,&B,&C);
    A--,B--;
    elist[i*2]=A;
    elist[i*2+1]=B;
    edges[A].push_back(i*2);
    edges[B].push_back(i*2+1);
    ws[i]=C;
  }
  dfs_size(0);
  dfs_hld(0);
  nodes_cnt=N-1;
  for(int i=0;i<N-1;i++){
    values[i]=DP(ws[i]);
  }
  std::vector<int>* path=dfs_rc(0);
  int root=reduce(Node::COMPRESS,*path);
  delete path;
  for(int i=N-1;i<nodes_cnt;i++){
    pull(i);
  }
  //dump(root),printf("\n");
  int64_t last=0;
  while(Q--){
    int64_t D,E;
    scanf("%I64d %I64d",&D,&E);
    D=(D+last)%(N-1);
    E=(E+last)%W;
    for(values[D]=DP(ws[D]=E);D!=root;D=parent[D]){
      pull(parent[D]);
    }
    /*
    for(int i=N-1;i<nodes_cnt;i++){
      pull(i);
      //printf("values[%d]=(%d,%d,%d,%d)\n",i,values[i].len,values[i].amax,values[i].bmax,values[i].diam);
    }
    */
    last=values[root].diam;
    printf("%I64d\n",last);
  }
}