#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> edges[300005];

int low[300005];
int pre[300005];
int pre_max=0;
bool vis[300005];
int depth[300005];

void dfs_2ecc(int node,int parent){
  low[node]=pre[node]=++pre_max;
  for(int other:edges[node]){
    if(other==parent) continue;
    if(!pre[other]){
      dfs_2ecc(other,node);
      low[node]=std::min(low[node],low[other]);
    }else{
      low[node]=std::min(low[node],pre[other]);
    }
  }
  //printf("pre[%d]=%d\n",node,pre[node]);
  //printf("low[%d]=%d\n",node,low[node]);
}

std::vector<int> stk;
int num_2ecc=0;
std::vector<int> shrunk[300005];

void dfs_recover(int node){
  vis[node]=true;
  if(low[node]==pre[node]){
    if(stk.size()){
      shrunk[num_2ecc].push_back(stk.back());
      shrunk[stk.back()].push_back(num_2ecc);
      //printf("(%d) == (%d)\n",num_2ecc,stk.back());
    }
    stk.push_back(num_2ecc++);
  }
  for(int child:edges[node]){
    if(!vis[child]) dfs_recover(child);
  }
  if(low[node]==pre[node]){
    stk.pop_back();
  }
}

void dfs_depth(int node,int parent){
  depth[node]=depth[parent]+1;
  for(int child:shrunk[node]){
    if(child==parent) continue;
    dfs_depth(child,node);
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }
  dfs_2ecc(0,0);
  dfs_recover(0);
  dfs_depth(0,0);
  int root=std::max_element(depth,depth+num_2ecc)-depth;
  dfs_depth(root,root);
  printf("%d\n",*std::max_element(depth,depth+num_2ecc)-depth[root]);
  return 0;
}