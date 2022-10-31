#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
using namespace std;
#define pb push_back
using ll = long long;
using db = long double;
const int N = 1 << 17, MOD = 1e9 + 7;
vector<int> adj[N], tree[N];
int n, m, q, u, v;
bitset<N> vis, in,cyc;
int par[17][N], head[N], sum[N], lvl[N];
void dfs(int u, int p){
  par[0][u] = p;
  vis[p] = 1;
  in[p] = 1;
  head[u] = u;
  for(auto v : adj[u])
  if(v != p){
    if(in[v]){
      cyc[v] = 1;
      for(int i = u; i != v; i = par[0][i])head[i] = v;
    } else {
      if(!vis[v])dfs(v, u);
    }
  }
  in[p] = 0;
}
void tdfs(int u){
  sum[u] += cyc[u];
  for(int i = 1; i < 17; i++)
    par[i][u] = par[i-1][par[i-1][u]];
  for(auto v : tree[u]){
    sum[v] = sum[u];
    lvl[v] = lvl[u] + 1;
    tdfs(v);
  }
}
int lca(int u, int v){
  if(lvl[u] > lvl[v])swap(u,v);
  int d = lvl[v] - lvl[u];
  for(int i = 0; i < 17; i++)
    if(d >> i & 1)
      v = par[i][v];
  if(u == v)return u;
  for(int i = 16; i >= 0; --i)
  if(par[i][v] != par[i][u]){
    u=par[i][u];
    v=par[i][v];
  }
  return par[0][u];
}
int main(){
#ifdef ONLINE_JUDGE
ios_base::sync_with_stdio(0);cin.tie(0);
#endif // ONLINE_JUDGE
  cin >> n >> m;
  while(m--){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
 
  ///if i build a super graph with cycles it becomes a tree
  ///so get cycles and build super graph
  ///count number of cycles from x to y t
 
  dfs(1, 0);
 
  for(int i = 1; i <= n; i++)
    par[0][i] = head[par[0][i]];
 
  for(int i = 1; i <= n; i++)
    if(i == head[i])
      tree[par[0][i]].pb(i);
 
  tdfs(1);
 
  cin >> q;
 
  while(q--){
      cin >> u >> v;
      u = head[u], v = head[v];
      int x = lca(u,v);
      int tot = sum[u] + sum[v] - 2 * sum[x] + cyc[x];
      int ans = 1, cur = 2;
      while(tot){
        if(tot & 1)
          ans = 1ll * ans * cur % MOD;
        tot>>=1;
        cur = 1ll * cur * cur % MOD;
      }
      cout << ans << '\n';
  }
 
 
  return 0;
}