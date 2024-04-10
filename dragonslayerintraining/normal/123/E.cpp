#include <cstdio>
#include <vector>
#include <numeric>

std::vector<int> edges[100005];

double xs[100005];
double ys[100005];

int size[100005];
double xsum[100005];

double ans=0;

void dfs1(int node,int parent){
  size[node]=1;
  xsum[node]=xs[node];
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs1(child,node);
    size[node]+=size[child];
    xsum[node]+=xsum[child];
  }
}

void dfs2(int node,int parent){
  double add=(xsum[0]-xsum[node])*(size[0]-size[node]);
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs2(child,node);
    add+=xsum[child]*size[child];
  }
  ans+=add*ys[node];
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  for(int i=0;i<N;i++){
    scanf("%lf %lf",&xs[i],&ys[i]);
  }
  double total_xs=std::accumulate(xs,xs+N,0);
  double total_ys=std::accumulate(ys,ys+N,0);
  for(int i=0;i<N;i++){
    xs[i]/=total_xs;
    ys[i]/=total_ys;
  }
  dfs1(0,0);
  dfs2(0,0);
  printf("%.10lf\n",ans);
  return 0;
}