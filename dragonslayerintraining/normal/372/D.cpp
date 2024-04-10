#include <cstdio>
#include <vector>
#include <set>

std::vector<int> edges[100005];
int who[100005];
int pre[100005];
int depth[100005];
int anc[100005][20];
int euler=0;

void dfs(int node,int parent){
  who[euler]=node;
  pre[node]=euler++;
  depth[node]=depth[parent]+1;
  anc[node][0]=parent;
  for(int k=1;k<20;k++){
    anc[node][k]=anc[anc[node][k-1]][k-1];
  }
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
  }
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int diff=depth[a]-depth[b];
  for(int k=20-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[a][k];
    }
  }
  if(a==b) return a;
  for(int k=20-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

int distance(int a,int b){
  return depth[a]+depth[b]-2*depth[lca(a,b)];
}

int subtree=0;
std::set<int> active;

std::set<int>::iterator active_next(std::set<int>::iterator it){
  return (++it==active.end())?active.begin():it;
}

std::set<int>::iterator active_prev(std::set<int>::iterator it){
  if(it==active.begin()){
    it=active.end();
  }
  return --it;
}

void insert(int node){
  active.insert(pre[node]);
  auto y=active.lower_bound(pre[node]);
  auto x=active_prev(y);
  auto z=active_next(y);
  subtree-=distance(who[*x],who[*z]);
  subtree+=distance(who[*x],who[*y]);
  subtree+=distance(who[*y],who[*z]);
}

void erase(int node){
  auto y=active.lower_bound(pre[node]);
  auto x=active_prev(y);
  auto z=active_next(y);
  subtree+=distance(who[*x],who[*z]);
  subtree-=distance(who[*x],who[*y]);
  subtree-=distance(who[*y],who[*z]);
  active.erase(pre[node]);
}


int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(0,0);
  int j=0;
  int best=1;
  for(int i=0;i<N;i++){
    insert(i);
    //printf("insert %d: subtree=%d\n",i+1,subtree);
    while(subtree>2*(K-1)){
      erase(j++);
      //printf("erase %d: subtree=%d\n",j-1+1,subtree);
    }
    best=std::max(best,i-j+1);
  }
  printf("%d\n",best);
  return 0;
}