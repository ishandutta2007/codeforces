#include <bits/stdc++.h>

using namespace std;

struct SAT2 {
  bool bad;
  int n;
  vector<bool> vis;
  vector<vector<int>> g;
  vector<vector<int>> ig;
  vector<int> ord;
  vector<int> comp;
  vector<int> sol;
  int cur;
  SAT2(int n) : n(n), comp(2 * n + 1, 0), vis(2 * n + 1, 0), g(2 * n + 1), ig(2 * n + 1), cur(0), sol(n + 1, -1), bad(0) {

  }

  void dfs(int a) {
    if (vis[a]) return;
    vis[a] = 1;
    for (auto& b : g[a]) {
      dfs(b);
    }
    ord.push_back(a);
  }

  void invdfs(int a) {
    if (vis[a]) return;
    comp[a] = cur;
    vis[a] = 1;
    for (auto& b : ig[a]) {
      invdfs(b);
    }
  }

  void onlyAddEdge(int a, int b) {
    assert(1 <= a && a <= 2 * n);
    assert(1 <= b && b <= 2 * n);
    g[a].push_back(b);
    ig[b].push_back(a);
  }

  void addImplication(int a, int b) {
    onlyAddEdge(a, b);
    onlyAddEdge(inv(b), inv(a));

  }
  void addOr(int a, int b) {
    assert(1 <= a && a <= 2 * n);
    assert(1 <= b && b <= 2 * n);
    addImplication(inv(a), b);
    addImplication(inv(b), a);
  }
  void forceTrue(int a) {
    assert(1 <= a && a <= 2 * n);
    addImplication(inv(a), a);
  }
  int inv(int x) {
    assert(1 <= x && x <= 2 * n);
    if (x <= n) return x + n;
    return x - n;
  }

  void solve() {
    for (int i = 1; i <= 2 * n; i++) {
      dfs(i);
    }
    reverse(ord.begin(), ord.end());
    for (int i = 1; i <= 2 * n; i++) {
      vis[i] = 0;
    }
    for (auto& i : ord) {
      if (vis[i]) continue;
      cur++;
      invdfs(i);
    }
    for (int i = 1; i <= n; i++) {
      if (comp[i] == comp[i + n]) {
        bad = 1;
        return;
      }
    }
    for (int i = 1; i <= n; i++) {
      sol[i] = (comp[i] > comp[i + n]);
    }
  }
};

const int N = (int) 2e4 + 7;
const int K = 10 + 7;
int n;
int m;
int k;
int id[N][K];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n >> m >> k;
    vector<vector<int>> history;
    SAT2 sat(n * k);
    {
      int cur_ind = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
          cur_ind++;
          id[i][j] = cur_ind;
        }
      }
    }
    sat.forceTrue(id[1][1]);
    for (int x = 1; x <= k; x++) {
      for (int i = 1; i < n; i++) {
        sat.addImplication(id[i][x], id[i + 1][x]);
      }
    }
    for (int x = 2; x <= k; x++) {
      for (int i = 1; i <= n; i++) {
        sat.addImplication(id[i][x], id[i][x - 1]);
      }
    }
    for (int im = 1; im <= m; im++) {
      int type;
      cin >> type;
      if (type == 1) {
        int i, x;
        cin >> i >> x;
        history.push_back({type, i, x});
        if (x + 1 > k) {
          sat.forceTrue(sat.inv(id[i][x]));
        } else {
          sat.addOr(sat.inv(id[i][x]), id[i][x + 1]);
        }
      }
      if (type == 2) {
        int i, j, sum;
        cin >> i >> j >> sum;
        history.push_back({type, i, j, sum});
        for (int iter = 1; iter <= 2; iter++) {
          for (int x = 1; x <= k; x++) {
            if (1 <= sum + 1 - x && sum + 1 - x <= k) {
              sat.addImplication(id[i][x], sat.inv(id[j][sum + 1 - x]));
            }
          }
          swap(i, j);
        }
      }
      if (type == 3) {
        int i, j, sum;
        cin >> i >> j >> sum;
        history.push_back({type, i, j, sum});
        for (int iter = 1; iter <= 2; iter++) {
          for (int x = 1; x <= k; x++) {
            if (1 <= sum - x && sum - x <= k) {
              if (x == k) {
                sat.forceTrue(id[j][sum - x]);
              } else {
                sat.addImplication(sat.inv(id[i][x + 1]), id[j][sum - x]);
              }
            }
          }
          swap(i, j);
        }
      }
    }
    sat.solve();
    if (sat.bad) {
      cout << "-1\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      int total = 0;
      for (int j = 1; j <= k; j++) {
        total += sat.sol[id[i][j]];
      }
      cout << total << " ";
    }
    cout << "\n";
  }
}