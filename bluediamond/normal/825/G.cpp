#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n, q, ret, mn[N], total = N;
vector<int> g[N];

void dfs(int a, int p = 0) {
  mn[a] = min(mn[a], a);
  for (auto &b : g[a]) {
    if (b == p) continue;
    mn[b] = min(mn[b], mn[a]);
    dfs(b, a);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 // freopen ()
  cin >> n >> q;
  for (int i = 1; i <= n; i++) mn[i] = N;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= q; i++) {
    int tp, x;
    cin >> tp >> x;
    x = (x + ret) % n + 1;
    if (i == 1) {
      dfs(x);
    }
    if (tp == 1) {
      total = min(total, mn[x]);
      continue;
    }
    ret = min(total, mn[x]);
    cout << ret << "\n";
  }
}