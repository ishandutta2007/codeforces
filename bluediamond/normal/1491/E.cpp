#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n, par[N], sub[N];
vector<int> fib, now;
vector<pair<int, int>> g[N];

void dfs(int node, int p = 0) {
  now.push_back(node);
  par[node] = p;
  sub[node] = 1;
  for (auto &it : g[node]) {
    int b = it.first;
    bool ok = it.second;
    if (ok && b != p) {
      dfs(b, node);
      sub[node] += sub[b];
    }
  }
}

bool ok(int node, int k) {
  if (fib[k] <= 2) {
    return 1;
  }
  int want1 = fib[k - 1];
  int want2 = fib[k - 2];
  now.clear();
  dfs(node);
  for (auto &x : now) {
    if (sub[x] == want1) {
      int p = par[x];
      for (auto &it : g[p]) {
        if (it.first == x) {
          assert(it.second);
          it.second = 0;
          break;
        }
      }
      for (auto &it : g[x]) {
        if (it.first == p) {
          assert(it.second);
          it.second = 0;
          break;
        }
      }
      vector<int> bg = now;
      if (!ok(p, k - 2)) return 0;
      now = bg;
      if (!ok(x, k - 1)) return 0;
      return 1;
    }
    if (sub[x] == want2) {
      int p = par[x];
      for (auto &it : g[p]) {
        if (it.first == x) {
          assert(it.second);
          it.second = 0;
          break;
        }
      }
      for (auto &it : g[x]) {
        if (it.first == p) {
          assert(it.second);
          it.second = 0;
          break;
        }
      }
      vector<int> bg = now;
      if (!ok(p, k - 1)) return 0;
      now = bg;
      if (!ok(x, k - 2)) return 0;
      return 1;
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

    //freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back({y, 1});
    g[y].push_back({x, 1});
  }
  fib.push_back(1);
  fib.push_back(1);
  while (fib.back() < n) {
    fib.push_back(fib[(int) fib.size() - 1] + fib[(int) fib.size() - 2]);
  }
  if (fib.back() != n) {
    cout << "NO\n";
    return 0;
  }
  cout << (ok(1, (int) fib.size() - 1) ? "YES" : "NO") << "\n";
}