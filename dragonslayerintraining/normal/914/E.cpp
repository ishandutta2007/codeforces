#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<int> edges[200005];
char label[200005];
int N;

int size[200005];
bool dead[200005];

int table[1<<20];
long long ans[200005];
long long add[200005];

void dfs_size(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if(child==parent||dead[child]) continue;
    dfs_size(child,node);
    size[node]+=size[child];
  }
}

int find_centroid(int node,int parent,int total_size){
  for(int child:edges[node]){
    if(child==parent||dead[child]) continue;
    if(size[child]*2>total_size){
      return find_centroid(child,node,total_size);
    }
  }
  return node;
}

template<int s>
void dfs_add(int node,int parent,int mask){
  //printf("dfs_add<%d>(%d,%d,%d)\n",s,node,parent,mask);
  mask^=(1<<(label[node]-'a'));
  table[mask]+=s;
  for(int child:edges[node]){
    if(child==parent||dead[child]) continue;
    dfs_add<s>(child,node,mask);
  }
}

void dfs_query(int node,int parent,int mask){
  add[node]=0;
  mask^=(1<<(label[node]-'a'));
  for(int k=0;k<20;k++){
    add[node]+=table[mask^(1<<k)];
  }
  add[node]+=table[mask];
  for(int child:edges[node]){
    if(child==parent||dead[child]) continue;
    dfs_query(child,node,mask);
    add[node]+=add[child];
  }
  //printf("ans[%d]+=%lld\n",node,add[node]);
  ans[node]+=add[node];
}

void dfs_query2(int node,int parent,int mask,int root){
  mask^=(1<<(label[node]-'a'));
  add[root]=0;
  for(int k=0;k<20;k++){
    add[root]+=table[mask^(1<<k)];
  }
  add[root]+=table[mask];
  ans[root]+=add[root];
  //printf("ans*[%d]+=%lld\n",node,add[node]);
  
  for(int child:edges[node]){
    if(child==parent||dead[child]) continue;
    dfs_query2(child,node,mask,root);
  }
}

void dfs_solve(int node){
  //printf("dfs_solve(%d)\n",node);
  dfs_size(node,-1);
  node=find_centroid(node,-1,size[node]);


  table[1<<(label[node]-'a')]++;
  for(int child:edges[node]){
    if(dead[child]) continue;
    dfs_query2(child,node,0,node);
    dfs_add<1>(child,node,1<<(label[node]-'a'));
  }
  /*
  for(int child:edges[node]){
    if(dead[child]) continue;
    dfs_add<-1>(child,node,1<<(label[node]-'a'));
  }
  table[1<<(label[node]-'a')]--;

  
  dfs_add<1>(node,-1,0);
  */
  for(int child:edges[node]){
    if(dead[child]) continue;
    dfs_add<-1>(child,node,1<<(label[node]-'a'));
    dfs_query(child,node,0);
    dfs_add<1>(child,node,1<<(label[node]-'a'));
  }
  dfs_add<-1>(node,-1,0);
  /*
  for(int i=0;i<(1<<20);i++){
    if(table[i]){
      fprintf(stderr,"dfs_solve(%d): table[%d] not cleared\n",node,i);
    }
  }
  */
  dead[node]=true;
  for(int child:edges[node]){
    if(dead[child]) continue;
    dfs_solve(child);
  }
}

void link(int x,int y){
  //printf("link(%d,%d)\n",x,y);
  edges[x].push_back(y);
  edges[y].push_back(x);
}

int main(){
  scanf("%d",&N);
  int oldN=N;
  for(int i=0;i<oldN-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    link(U,V);
  }
  for(int i=0;i<oldN;i++){
    scanf(" %c",&label[i]);
  }
  dfs_solve(0);
  for(int i=0;i<oldN;i++){
    printf("%lld\n",ans[i]+1);
  }
}