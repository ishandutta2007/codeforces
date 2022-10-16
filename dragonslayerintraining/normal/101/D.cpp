#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int> > adj[100005];
int size[100005];
int length[100005];

void dfs_size(int x){
  size[x]=1;
  length[x]=0;
  for(auto e:adj[x]){
    int y=e.first,len=e.second;
    adj[y].erase(std::find(adj[y].begin(),adj[y].end(),std::make_pair(x,len)));
    dfs_size(y);
    length[y]+=len*2;
    length[x]+=length[y];
    size[x]+=size[y];
  }
}

int t=0;
long long ans=0;

void dfs_solve(int x){
  std::sort(adj[x].begin(),adj[x].end(),[](std::pair<int,int> a,std::pair<int,int> b){
      return 1LL*size[b.first]*length[a.first]<1LL*size[a.first]*length[b.first];});
  ans+=t;
  for(auto e:adj[x]){
    int y=e.first,len=e.second;
    t+=len;
    dfs_solve(y);
    t+=len;
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int A,B,L;
    scanf("%d %d %d",&A,&B,&L);
    A--,B--;
    adj[A].emplace_back(B,L);
    adj[B].emplace_back(A,L);
  }
  dfs_size(0);
  dfs_solve(0);
  printf("%.10lf\n",(double)ans/(N-1));
}