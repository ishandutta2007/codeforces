#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

struct Edge {
  int u, v; //Fill this
  int bicomp; //Index of the bic. comp. (don't fill)
};

vi bic_vertex; // Vertex repr for each bic. comp.
vi num, low; //Initialize to -1
int act, bicos; //Put this to zero for every testcase
stack<int> S;

void dfs(int u, vvi& adj, vector<Edge>& E, int p=-1){
  num[u] = low[u] = act++;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = E[adj[u][i]].v;
    if (v == u) v = E[adj[u][i]].u;
    if (num[v] == -1) {
      int size = S.size();
      S.push(adj[u][i]);
      dfs(v, adj, E, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[u]) {
        while (S.size() != size) {
          E[S.top()].bicomp = bicos;
          S.pop();
        }
        bic_vertex.push_back(u);
        ++bicos;
      }
    }
    else if (v != p and num[v] < num[u]) {
      S.push(adj[u][i]);
      low[u] = min(low[u], num[v]);
    }
  }
}

vvi G;
vi P;
vvi D;
const int L = 20;

void f(int x, int d = 0, int p = -1) {
  P[x] = d;
  D[x][0] = p;
  int l = 0;
  while (D[x][l] != -1) {
    D[x][l+1] = D[D[x][l]][l];
    l++;
  }
  for (auto y : G[x]) {
    if (y == p) continue;
    f(y, d+1, x);
  }
}

int lca(int x, int y) {
  if (P[x] < P[y]) swap(x,y);
  int l = L-1;
  while (P[x] > P[y]) {
    int x0 = D[x][l];
    if (x0 != -1 and P[x0] >= P[y]) x = x0;
    --l;
  }
  if (x == y) return x;
  l = L;
  while (l--) {
    int x0 = D[x][l];
    int y0 = D[y][l];
    if (x0 != y0) {
      x = x0;
      y = y0;
    }
  }
  return D[x][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vvi adj(n);
  vector<Edge> E(m);
  num = low  = vi(n, -1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    adj[x].push_back(i);
    adj[y].push_back(i);
    E[i].u = x;
    E[i].v = y;
  }
  act = bicos = 0;
  dfs(0, adj, E);
  vector<set<int> > B(bicos);
  for (int i = 0; i < m; ++i) {
    B[E[i].bicomp].insert(E[i].u);
    B[E[i].bicomp].insert(E[i].v);
  }

  int nm = n + bicos;
  G = vvi(nm);
  P = vi(nm);
  D = vvi(nm, vi(L,-1));
  for (int i = 0; i < bicos; ++i) {
    int y = n + i;
    for (auto x : B[i]) {
      G[y].push_back(x);
      G[x].push_back(y);
    }
  }
  f(0);

  while (q--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    int z = lca(x,y);
    int rr = P[x] + P[y] -2*P[z];
    cout << rr/2 << '\n';
  }
}