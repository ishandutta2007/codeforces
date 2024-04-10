#include <bits/stdc++.h>

using namespace std;

bool home = 1;

#define int long long
mt19937 rng((long long) (new char));

const int N = (int) 1e5 + 7;
const int INF=(int) 1e18+7;
const int K=20;
int n,m,lvlvlvlvdep[N],dep[N],ff[N],ss[N],lg2[2*N],tt;
pair<int, int> rmq[K][2*N];
vector<pair<int,int>> g[N];
set<int> specnodes;
int id[N];

void dfs(int a){
  ff[a]=ss[a]=++tt;
  rmq[0][tt]={lvlvlvlvdep[a], a};
  vector<pair<int,int>> kids;
  for (auto &it:g[a]){
    int b=it.first,len=it.second;
    if(lvlvlvlvdep[b]==-1){
      lvlvlvlvdep[b]=1+lvlvlvlvdep[a];
      dep[b]=len+dep[a];
      dfs(b);
      ss[a]=++tt;
      rmq[0][tt]={lvlvlvlvdep[a], a};
    }else{
      if(lvlvlvlvdep[b]<lvlvlvlvdep[a]-1){
        specnodes.insert(a);
      }
    }
  }
}

int lca(int a,int b){
  if(ff[a]>ss[b]) {
    swap(a,b);
  }
  assert(ff[a]<=ss[b]);
  a=ff[a];
  b=ss[b];
  int k=lg2[b-a+1];
  return min(rmq[k][a],rmq[k][b-(1<<k)+1]).second;
}


int getrawdist(int a,int b){
  int c=lca(a,b);
  return dep[a]+dep[b]-2*dep[c];
}

int dist[33][N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>m;
  for (int i=1;i<=n;i++){
    lvlvlvlvdep[i]=-1;
  }
  for (int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  lvlvlvlvdep[1]=0, dfs(1);
  int sp=-1;
  for (auto &x:specnodes){
    sp++;
    priority_queue<pair<int, int>> q;
    for(int i=1;i<=n;i++)dist[sp][i]=+INF;
    dist[sp][x]=0;
    q.push({0, x});
    while(!q.empty()){
      auto it=q.top();
      q.pop();
      if(dist[sp][it.second]!=-it.first)continue;
      int a=it.second;
      for (auto &itr:g[a]){
        int b=itr.first,cst=itr.second;
        if(dist[sp][a]+cst<dist[sp][b]){
          dist[sp][b]=dist[sp][a]+cst;
          q.push({-dist[sp][b],b});
        }
      }
    }
  }
  for (int k=1;(1<<k)<=tt;k++){
    for (int i=1;i+(1<<k)-1<=tt;i++){
      rmq[k][i]=min(rmq[k-1][i],rmq[k-1][i+(1<<(k-1))]);
    }
  }
  for (int i=2;i<=tt;i++){
    lg2[i]=1+lg2[i/2];
  }
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    int sol=getrawdist(a,b);
    for (int v=0;v<(int)specnodes.size();v++){
      sol=min(sol,dist[v][a]+dist[v][b]);
    }
    cout<<sol<<"\n";
  }

  return 0;
}