#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

struct hierholzer {
  int n_nodes, n_edges;
  vector<pair<int, int>>* gr;
  vector<bool> rem;
  vector<int> stack, res;

  hierholzer(int n_nodes_, int n_edges_, vector<pair<int, int>>* gr_)
    :n_nodes(n_nodes_), n_edges(n_edges_), gr(gr_), rem(n_edges)
  { }

  void run(int start_node = 0) {
    stack.push_back(start_node);
    for (; len(stack); ) {
      int u = stack.back();
      while (len(gr[u]) and rem[gr[u].back().yy]) gr[u].pop_back();
      if (len(gr[u]) == 0) {
        res.push_back(u);
        stack.pop_back();
        continue;
      } 
      stack.push_back(gr[u].back().xx);
      rem[gr[u].back().yy] = 1;
    }
  }
};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
      int n, m;
      cin >> n >> m;
      vector<vector<pair<int, int>>> gr(n + 1);
      rep(i, m) {
        int u, v; cin >> u >> v;
        --u, --v;
        gr[u].emplace_back(v, i);
        gr[v].emplace_back(u, i);
      }

      int ans = n;
      rep(i, n)
        if (len(gr[i]) & 1) {
          gr[i].emplace_back(n, m);
          gr[n].emplace_back(i, m);
          ++m;
          --ans;
        }
      if (len(gr[n]) & 1) gr[n].emplace_back(n, ++m);
      cout << ans << '\n';

      hierholzer euler_cycle = hierholzer(n + 1, m, &gr[0]);
      rep(i, n + 1) {
        if (len(gr[i])) euler_cycle.run(i);
        auto& res = euler_cycle.res;
        rep(f, len(res) - 1) {
          if (res[f] == n or res[f + 1] == n) continue;
          cout << res[f] + 1 << ' ' << res[f + 1] + 1 << '\n';
        }
        res.clear();
      }

    }

    return 0;
}