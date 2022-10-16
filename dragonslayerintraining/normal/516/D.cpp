#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

struct Skew{
  Skew* left,*right;
  long long val;
  int size;
}skew[100005];

Skew* merge(Skew* a,Skew* b){
  if(a==NULL) return b;
  if(b==NULL) return a;
  if(a->val>b->val) std::swap(a,b);
  b->size+=a->size;
  b->right=merge(b->right,a);
  std::swap(b->left,b->right);
  return b;
}

Skew* extract(Skew* a){
  Skew* left=a->left,*right=a->right;
  //delete a;
  return merge(left,right);
}

std::vector<std::pair<int,int> > edges[100005];

long long far[100005];

void dfs1(int node,int parent){
  far[node]=0;
  for(auto e:edges[node]){
    int child=e.first;
    if(child==parent) continue;
    dfs1(child,node);
    far[node]=std::max(far[node],far[child]+e.second);
  }
}

void dfs2(int node,int parent,long long above){
  std::vector<std::pair<long long,int> > top;
  top.push_back({above,-1});
  for(auto e:edges[node]){
    if(e.first==parent) continue;
    top.push_back({far[e.first]+e.second,e.first});
  }
  std::sort(top.begin(),top.end());
  std::reverse(top.begin(),top.end());
  for(auto e:edges[node]){
    if(e.first==parent) continue;
    int child=e.first;
    dfs2(child,node,top[child==top[0].second].first+e.second);
  }
  far[node]=std::max(far[node],above);
}

long long L;
int best;
Skew* dfs3(int node,int parent){
  Skew* res=&skew[node];
  skew[node]=Skew{NULL,NULL,far[node],1};
  for(auto e:edges[node]){
    if(e.first==parent) continue;
    res=merge(res,dfs3(e.first,node));
  }
  while(res->val-far[node]>L){
    res=extract(res);
  }
  best=std::max<int>(best,res->size);
  return res;
}
  
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int X,Y,W;
    scanf("%d %d %d",&X,&Y,&W);
    X--,Y--;
    edges[X].push_back({Y,W});
    edges[Y].push_back({X,W});
  }
  dfs1(0,0);
  dfs2(0,0,0);
  int root=std::min_element(far,far+N)-far;
  int Q;
  scanf("%d",&Q);
  while(Q--){
    scanf("%lld",&L);
    best=0;
    dfs3(root,root);
    printf("%d\n",best);
  }
}