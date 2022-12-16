#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
vector<int> adj[N];
vector<int> par[N];
bool has_ac_par[N];
bool ac[N];
int in[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
      adj[i].clear();
      par[i].clear();
      in[i] = 0;
      ac[i] = 0;
      has_ac_par[i] = 0;
    }
    for (int i=1; i<=m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      par[v].push_back(u);
      ++in[v];
    }
    queue<int> q;
    for (int i=1; i<=n; ++i) {
      if (in[i] == 0) {
        q.push(i);
      }
    }
    vector<int> topo;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      topo.push_back(u);
      for (auto& v : adj[u]) {
        if (--in[v] == 0) {
          q.push(v);
        }
      }
    }
    int close = 0;
    for (auto& u : topo) {
      has_ac_par[u] = 0;
      bool has_app = 0;
      for (auto& p : par[u]) {
        if (ac[p]) {
          has_ac_par[u] = 1;
        }
        if (ac[p] && has_ac_par[p]) {
          has_app = 1;
        }
      }
      ac[u] = !has_app;
      close += has_app;
    }
    cout << close << "\n";
    for (int i=1; i<=n; ++i) {
      if (!ac[i]) {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}