#include <bits/stdc++.h>

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

struct Dinic {
  struct Edge {
    int u, v;
    long long cap, flow;
    Edge() {}
    Edge(int u, int v, long long cap): u(u), v(v), cap(cap), flow(0) {}
  }; 
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, long long cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
  long long DFS(int u, int T, long long flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        long long amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (long long pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  long long MaxFlow(int S, int T) {
    long long total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (long long flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    fast_cin();
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n + 1, vector<bool>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        string inp; cin >> inp;
        for (int j = 0; j < m; ++j) {
            a[i][j] = (inp[j] == 'B');
        }
    }
    auto b = a;
    int base_cost = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = (a[i][j] ^ a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1]);
            base_cost += b[i][j];
        }
    }
    Dinic dinic(n + m + 2);
    for (int i = 0; i < n; ++i) {
        dinic.AddEdge(0, i + 1, 1);
    }
    for (int j = 0; j < m; ++j) {
        dinic.AddEdge(n + j + 1, n + m + 1, 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == n - 1 or j == m - 1) {
                continue;
            }
            if (b[i][j] and b[i][m - 1] and b[n - 1][j]) {
                dinic.AddEdge(i + 1, n + j + 1, 1);
            }
        }
    }
    int f = dinic.MaxFlow(0, n + m + 1);
    int ans = base_cost - 2 * (f / 2);
    if (f % 2 == 1 and b[n - 1][m - 1]) {
        ans -= 2;
    }
    cout << ans << '\n';
}