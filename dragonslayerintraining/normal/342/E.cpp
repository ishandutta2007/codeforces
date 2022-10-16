#include <iostream>
#include <vector>

int N,M;
std::vector<int> edges[100000];
int size[100000];
int layer[100000];
std::vector<std::pair<int,int> > ancestors[100000];
int closest[1000000];

void dfs_size(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if((child!=parent)&&(layer[child]==0)){
      dfs_size(child,node);
      size[node]+=size[child];
    }
  }
}

void dfs_inform(int node,int parent,int root,int dist){
  ancestors[node].push_back(std::make_pair(root,dist));
  for(int child:edges[node]){
    if((child!=parent)&&(layer[child]>=layer[root])){
      dfs_inform(child,node,root,dist+1);
    }
  }
}

int find_centroid(int node,int parent,int total_size){
  for(int child:edges[node]){
    if((child!=parent)&&(layer[child]==0)){
      if(size[child]*2>=total_size){
	return find_centroid(child,node,total_size);
      }
    }
  }
  return node;
}

void dfs_decompose(int node,int l){
  dfs_size(node,-1);
  node=find_centroid(node,node,size[node]);
  layer[node]=l;
  for(int child:edges[node]){
    if(layer[child]==0){
      dfs_decompose(child,l+1);
    }
  }
  dfs_inform(node,-1,node,0);
}


int main(){
  std::cin>>N>>M;
  for(int i=0;i<N-1;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs_decompose(0,1);
  std::fill(closest,closest+N,1e9);
  for(std::pair<int,int> anc:ancestors[0]){
    closest[anc.first]=std::min(closest[anc.first],anc.second);
  }
  for(int i=0;i<M;i++){
    int T,V;
    std::cin>>T>>V;
    V--;
    if(T==1){
      for(std::pair<int,int> anc:ancestors[V]){
	closest[anc.first]=std::min(closest[anc.first],anc.second);
      }
    }else{
      int best=1e9;
      for(std::pair<int,int> anc:ancestors[V]){
	best=std::min(best,closest[anc.first]+anc.second);
      }
      std::cout<<best<<std::endl;
    }
  }
  return 0;
}