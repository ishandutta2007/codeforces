#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 1e5 + 7;
int n, e[N][2], indeg[N];
vector<int> g[N];

bool ok(int m) {
  for (int i = 1; i <= n; i++) {
    indeg[i] = 0;
    g[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    indeg[e[i][1]]++;
    g[e[i][0]].push_back(e[i][1]);
  }
  queue<int> s;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      s.push(i);
    }
  }
  for (int step = 1; step <= n; step++) {
    if ((int) s.size() != 1) {
      return 0;
    }
    int x = s.front();
    s.pop();
    for (auto &y : g[x]) {
      indeg[y]--;
      if (indeg[y] == 0) {
        s.push(y);
      }
    }
  }

  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int ed;

  cin >> n >> ed;
  for (int i = 1; i <= ed; i++) {
    cin >> e[i][0] >> e[i][1];
  }

  int l = 1, r = ed, sol = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m)) {
      sol = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << sol << "\n";

  return 0;
}