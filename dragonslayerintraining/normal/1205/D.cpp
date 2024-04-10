#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> edges[1005];
int size[1005];
int pot[1005];

void dfs_size(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs_size(child,node);
    size[node]+=size[child];
  }
}

int find_centroid(int node,int parent,int total_size){
    for(int child:edges[node]){
    if(child==parent) continue;
    if(size[child]*2>total_size){
      return find_centroid(child,node,total_size);
    }
  }
  return node;
}

int next_id=1;

void dfs_assign(int node,int parent,int inc){
  pot[node]=next_id;
  next_id+=inc;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs_assign(child,node,inc);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_size(0,0);
  int root=find_centroid(0,0,N);
  //printf("root=%d\n",root);
  dfs_size(root,root);
  std::vector<std::pair<int,int> > small,large;//(size,sub)
  for(int child:edges[root]){
    small.push_back({size[child],child});
  }
  std::sort(small.begin(),small.end());
  int large_total=0;
  while((N-large_total)*(large_total+1)<2*N*N/9){
    large.push_back(small.back());
    large_total+=small.back().first;
    small.pop_back();
  }
  for(auto it:small){
    dfs_assign(it.second,root,1);
  }
  int skip=next_id;
  for(auto it:large){
    dfs_assign(it.second,root,skip);
  }
  /*
  for(int i=0;i<N;i++){
    printf("pot[%d]=%d\n",i,pot[i]);
  }
  */
  for(int i=0;i<N;i++){
    for(int j:edges[i]){
      if(j>i){
	printf("%d %d %d\n",i+1,j+1,std::abs(pot[i]-pot[j]));
      }
    }
  }
}