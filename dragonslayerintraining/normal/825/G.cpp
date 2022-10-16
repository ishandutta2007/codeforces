#include <cstdio>
#include <vector>

std::vector<int> edges[1000000];

int parent[1000000];
int min[1000000];
bool vis[1000000];

void dfs_parent(int node,int par){
  parent[node]=par;
  min[node]=node;
  min[node]=std::min(node,min[par]);
  for(int child:edges[node]){
    if(child!=par){
      dfs_parent(child,node);
    }
  }
}

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }
  int root;
  scanf(" 1 %d",&root);
  //printf("ROOT %d\n",root);
  dfs_parent(root,root);
  vis[root]=true;
  
  int last=0;
  while(--Q>0){
    int T,Z;
    scanf("%d %d",&T,&Z);
    int X=(Z+last)%N;
    //printf("Query: %d %d\n",T,X+1);
    if(T==1){
      while(!vis[X]){
	vis[X]=true;
	min[root]=std::min(min[root],X);
	X=parent[X];
      }
    }else{
      last=1+std::min(min[X],min[root]);
      printf("%d\n",last);
    }
  }
  return 0;
}