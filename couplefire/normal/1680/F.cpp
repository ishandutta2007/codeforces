#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
vector<int> G[N], children[N];
bool vis[N], col[N];
int tin[N], tout[N], par[N];
vector<pair<int, int>> bad_edges, good_edges;
int req[N];
int timer = 0;
int top;
bool mark[N], anc_of_top[N];

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs(int v, int p) {
  par[v] = p;
  if (p != v) children[p].push_back(v);
  vis[v] = 1;
  tin[v] = timer++;
  for (int u: G[v]) {
    if (u != p) {
      if (!vis[u]) {
        col[u] = 1-col[v];
        dfs(u, v);
      }
      else {
        if (tin[u] <= tin[v]) {
          if (col[u] == col[v]) {
            bad_edges.emplace_back(u, v);
          }
          else {
            good_edges.emplace_back(u, v);
          }
        }
      }
    }
  }
  tout[v] = timer++;
}

void dfs2(int v) {
  int c = 0;
  for (int u: children[v]) {
    dfs2(u);
    if (mark[u]) c++;
  }
  if (mark[v] || c >= 2) top = v;
  if (c) mark[v] = 1;
}

void dfs3(int v) {
  for (int u: children[v]) {
    dfs3(u);
    if (anc_of_top[u]) {
      anc_of_top[v] = 1;
    }
  }
  if (!anc_of_top[v]) {
    req[par[v]] += req[v];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    timer = 0;
    dfs(1, 1);

    if (bad_edges.size() <= 1) {
      cout << "YES\n";
      if (bad_edges.size() && !col[bad_edges[0].first]) {
        for (int i = 1; i <= n; i++) {
          col[i] ^= 1;
        }
      }
      for (int i = 1; i <= n; i++) {
        cout << col[i];
      }
      cout << '\n';
    }

    else {
      for (pair<int, int>& p: bad_edges) {
        mark[p.second] = 1;
      }
      dfs2(1);
      anc_of_top[top] = 1;
      for (pair<int, int>& p: good_edges) {
        req[p.second]++;
        req[p.first]--;
      }
      dfs3(1);

      bool fail = 0;
      int s = req[top];
      while (s) {
        top = par[top];
        s += req[top];
      }
      for (pair<int, int>& p: bad_edges) {
        if (!is_ancestor(p.first, par[top])) {
          fail = 1;
          break;
        }
      }
      if (top == 1) fail = 1;
      if (fail) {
        cout << "NO\n";
      }
      else {
        cout << "YES\n";
        if (col[top]) {
          for (int i = 1; i <= n; i++) {
            col[i] ^= 1;
          }
        }
        for (int i = 1; i <= n; i++) {
          cout << (col[i]^(is_ancestor(top, i)));
        }
        cout << '\n';
      }
    }
    
    bad_edges.clear();
    good_edges.clear();
    fill(G+1, G+n+1, vector<int>());
    fill(children+1, children+n+1, vector<int>());
    fill(vis+1, vis+n+1, 0);
    fill(req+1, req+n+1, 0);
    fill(mark+1, mark+n+1, 0);
    fill(anc_of_top+1, anc_of_top+n+1, 0);
  }
}