#include <iostream>
#include <stdint.h>
#include <vector>

bool vis[50000];
int64_t size[50000];

int64_t answer=0;

std::vector<int64_t> edges[50000];
int64_t K;

void dfs_size(int64_t node,int64_t parent){
  size[node]=1;
  for(int64_t child:edges[node]){
    if(child!=parent&&!vis[child]){
      dfs_size(child,node);
      size[node]+=size[child];
    }
  }
}

void dfs_depth(int64_t node,int64_t parent,std::vector<int64_t>& cnt,int64_t d){
  while(cnt.size()<=d){
    cnt.push_back(0);
  }
  cnt[d]++;
  for(int64_t child:edges[node]){
    if(child!=parent&&!vis[child]){
      dfs_depth(child,node,cnt,d+1);
    }
  }
}

void dfs_cent(int64_t node){
  dfs_size(node,node);
  int64_t subtree=size[node];
  int64_t parent=node;
  while(true){
    int64_t heavy=-1;
    for(int64_t child:edges[node]){
      if(child!=parent&&!vis[child]&&size[child]*2>=subtree){
	heavy=child;
	break;
      }
    }
    if(heavy==-1){
      break;
    }
    parent=node;
    node=heavy;
  }
  vis[node]=true;
  std::vector<int64_t> prev(1,1);
  for(int64_t child:edges[node]){
    if(!vis[child]){
      std::vector<int64_t> cnt;
      dfs_depth(child,node,cnt,1);
      for(int64_t i=std::max<int64_t>(0,K-cnt.size()+1);i<=std::min<int64_t>(prev.size()-1,K);i++){
	answer+=prev[i]*cnt[K-i];
      }
      if(prev.size()<cnt.size()){
	prev.resize(cnt.size());
      }
      for(int64_t i=0;i<cnt.size();i++){
	prev[i]+=cnt[i];
      }
    }
  }
  for(int64_t child:edges[node]){
    if(!vis[child]){
      dfs_cent(child);
    }
  }
}

int main(){
  int64_t N;
  std::cin>>N>>K;
  for(int64_t i=0;i<N-1;i++){
    int64_t A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs_cent(0);
  std::cout<<answer<<std::endl;
  return 0;
}