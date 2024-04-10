#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LOGN = 20;
const int inf = 1e8;

int n, m, sub[N];
int par[N][LOGN], level[N], up[N];
set<int> adj[N];
int ans[N];

void dfs0(int v) {
  if(par[v][0] != v) {
    for(int i = 0; i+1 < LOGN && par[v][i] != -1; i++)
      par[v][i+1] = par[par[v][i]][i];
    level[v] = level[par[v][0]] + 1;
  }
  for(int u : adj[v]) if(u != par[v][0]) {
    par[u][0] = v;
    dfs0(u);
  }
}

void preproces(){
  memset(par, -1, sizeof par);
  par[0][0] = 0;
  level[0] = 0;
  dfs0(0);
}
int lca(int v, int u) {
  if(level[v] < level[u])
    swap(u, v);
  int dif = level[v] - level[u];
  for(int i = 0; dif; dif >>=1, i++)
    if(dif & 1)
      v = par[v][i];
  if(v == u)
    return v;
  assert(level[v] == level[u]);
  for(int i = LOGN-1; i>= 0; i--)
    if(par[v][i] != par[u][i])
      v = par[v][i], u = par[u][i];
  return par[v][0];
}
int dist(int v,int u) {
  return level[v] + level[u] - 2*level[lca(v, u)];
}

int dfs1(int v, int p = -1) {
  sub[v] = 1;
  for(int u : adj[v]) if(u != p) {
    sub[v] += dfs1(u, v);
  }
  // cout << v << " " << sub[v] << " sub" << endl;
  return sub[v];  
}

int dfs2(int v, int low, int p = -1) {
  for(int u : adj[v]) if(u != p) {
    if(sub[u] > low)
      return dfs2(u, low, v);
  }
  return v;
}

void decompose(int v, int p = -1) {
  int size = dfs1(v);
  // cout << size << endl;
  int ctr = dfs2(v, size/2);
  if(p == -1)
    p = ctr;
  up[ctr] = p;
  // cout << "decompose " << ctr << " "  << p << endl;
  for(int u : adj[ctr]) {
    adj[u].erase(ctr);
    decompose(u, ctr);
  }
  adj[ctr].clear();
}

void update(int v) {
  int x = v;
  while(1) {  
    ans[x] = min(ans[x], dist(v, x));
    
    if(x == up[x])
      return;
    x = up[x];
  }
}

int query(int v) {
  int ret = inf;
  int x = v;
  while(1) {
    ret = min(ret, ans[x] + dist(v, x));
    
    if(up[x] == x)
      break;
    x = up[x];
  }
  return ret;
}



int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i<n;i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  preproces();
  decompose(0);
  for(int i = 0; i<n; i++) ans[i] = inf;
  update(0);
  while(m--) {
    int t, v;
    scanf("%d%d", &t, &v); v--;
    if(t == 1)
      update(v);
    else
      printf("%d\n", query(v));
  }
  return 0;
}