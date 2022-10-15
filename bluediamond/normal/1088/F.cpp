#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

#define int long long
const int K=21;
const int N=(int) 5e5+7;
const int INF=(int)1e18+7;
int n,v[N],par[K][N],dep[N],lg[N];
vector<int> g[N];

void build(int a,int p=0){
  par[0][a]=p;
  for(int k=1;k<K;k++){
    par[k][a]=par[k-1][par[k-1][a]];
  }
  vector<int> kids;
  for(auto&b:g[a]){
    if(b==p) continue;
    kids.push_back(b);
    dep[b]=1+dep[a];
    build(b,a);
  }
  g[a]=kids;
}

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


  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }

  for(int i=2;i<=n;i++){
    lg[i]=1+lg[i/2];
  }

  for(int i=1;i<n;i++){
    int a, b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int k=0;

  for(int i=1;i<=n;i++){
    while((1<<k)<i){
      k++;
    }
    lg[i]=k;
  }


  int root=1;
  for(int i=2;i<=n;i++){
    if(v[i]<v[root]){
      root=i;
    }
  }

  build(root);

  ll print=0;

  for(int i=1;i<=n;i++){
    if(i==root) continue;
    int sol=INF;
    int j=i;
    j=par[0][j];
    if(j){
      int now=lg[dep[i]-dep[j]];
      int edge_cost=(now+1)*v[j];
      sol=min(sol,edge_cost);
    }
    for(int s=0;s<K;s++){
      j=par[s][j];
      if(!j) break;
      int now=lg[dep[i]-dep[j]];
      int edge_cost=(now+1)*v[j];
      sol=min(sol,edge_cost);
    }
    sol=min(sol,(lg[dep[i]]+1)*v[root]);
    print+=sol+v[i];
  }

  cout<<print<<"\n";

  return 0;
}