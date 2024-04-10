#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int ll

int func(int n) {return n * (n - 1) / 2;}

const int N = (int) 2e5 + 7;
int n, par[N], dep[N];
bool vis[N];
vector<int> g[N], path;

void dfs(int a, int p = -1) {
  par[a] = p;
  for (auto &b : g[a]) {
    if (dep[b] == -1) dep[b] = 1 + dep[a], dfs(b, a);
    else if (dep[b] < dep[a] - 1) {
      int i = a;
      path = {i};
      while (i != b) i = par[i], path.push_back(i);
    }
  }
}

int cnt(int a) {
  vis[a] = 1;
  int ret = 1;
  for (auto &b : g[a]) if (!vis[b]) ret += cnt(b);
  return ret;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear(), dep[i] = -1, vis[i] = 0;
    for (int i = 1; i <= n; i++) {
      int x, y; cin >> x >> y;
      g[x].push_back(y), g[y].push_back(x);
    }
    dep[1] = 0; dfs(1);
    int ret = 2 * func(n);
    for (auto &x : path) vis[x] = 1;
    for (auto &x : path) ret -= func(cnt(x));
    cout << ret << "\n";
  }
}