#include <bits/stdc++.h>


using namespace std;

bool home = 1;



signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> dep(n, -1), par(n, -1);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<int> q = { 0 };
    dep[0] = 0;
    for (int it = 0; it < (int)q.size(); it++) {
      int a = q[it];
      for (auto& b : g[a]) {
        if (dep[b] == -1) {
          dep[b] = dep[a] + 1;
          par[b] = a;
          q.push_back(b);
        }
      }
    }
    const int K = 20;
    vector<vector<int>>jump(K, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
      jump[0][i] = par[i];
    }
    for (int k = 1; (1 << k) <= n; k++) {
      for (int i = 0; i < n; i++) {
        if (jump[k - 1][i] == -1) {
          jump[k][i] = -1;
        }
        else {
          jump[k][i] = jump[k - 1][jump[k - 1][i]];
        }
      }
    }
    auto getlca = [&](int a, int b) {
      if (dep[a] < dep[b]) {
        swap(a, b);
      }
      assert(dep[a] >= dep[b]);
      int dif = dep[a] - dep[b];
      for (int k = K - 1; k >= 0; k--) {
        if (dif & (1 << k)) {
          a = jump[k][a];
        }
      }
      assert(dep[a] == dep[b]);
      if (a == b) {
        return a;
      }
      for (int k = K - 1; k >= 0; k--) {
        if (jump[k][a] != jump[k][b]) {
          a = jump[k][a];
          b = jump[k][b];
        }
      }
      assert(a != b);
      assert(par[a] == par[b]);
      return par[a];
    };
    auto getdist = [&](int a, int b) {
      return dep[a] + dep[b] - 2 * dep[getlca(a, b)];
    };
    /// given limit I want to know the biggest dist that can reach it
    const int INF = (int)1e9;
    vector<int> sol(n + 1, INF);
    int maxdep = *max_element(dep.begin(), dep.end());
    int x = -1, y = -1;
    for (int limit = maxdep; limit >= 0; limit--) {
      while (!q.empty() && dep[q.back()] > limit) {

        int z = q.back();
        q.pop_back();
        /// add vertex a
        if (x == -1) {
          assert(y == -1);
          x = y = z;
        }
        else {
          int xy = getdist(x, y);
          int xz = getdist(x, z);
          int yz = getdist(y, z);
          if (max(xz, yz) > xy) {
            if (xz > yz) {
              y = z;
            }
            else {
              x = z;
            }
          }
        }

      }
      int radius = (getdist(x, y) + 1) / 2;
      int X = limit - radius;
      if (X >= 1) {
        sol[X] = min(sol[X], limit);
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      sol[i] = min(sol[i], sol[i + 1]);

    }
    for (int i = 1; i <= n; i++) {
      if (sol[i] == INF) {
        sol[i] = maxdep;
      }
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
}