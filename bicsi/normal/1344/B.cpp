#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<string> v(n);
  vector<int> minr(n, 1e9), maxr(n, -1e9);
  vector<int> minc(m, 1e9), maxc(m, -1e9);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    for (int j = 0; j < m; ++j) {
      if (v[i][j] == '#') {
        minr[i] = min(minr[i], j);
        maxr[i] = max(maxr[i], j);
        minc[j] = min(minc[j], i);
        maxc[j] = max(maxc[j], i);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = minr[i]; j <= maxr[i]; ++j) {
      if (v[i][j] != '#') fail();
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = minc[j]; i <= maxc[j]; ++i) {
      if (v[i][j] != '#') fail();
    }
  }

  vector<pair<int, int>> q;
  auto push = [&](int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == '.') return;
    q.emplace_back(i, j);
    v[i][j] = '.';
  };
  
  bool empty_row = false, empty_col = false;
  for (int i = 0; i < n; ++i) {
    bool ok = true;
    for (int j = 0; j < m; ++j)
      if (v[i][j] == '#')
        ok = false;
    if (ok) empty_row = true;
  }

  for (int j = 0; j < m; ++j) {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (v[i][j] == '#')
        ok = false;
    }
    if (ok) empty_col = true;
  }

  if (empty_row ^ empty_col) fail();

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j] == '.') continue;
      ans += 1;
      q.clear();
      push(i, j);
      for (int it = 0; it < (int)q.size(); ++it) {
        int x, y; tie(x, y) = q[it];
        push(x - 1, y);
        push(x + 1, y);
        push(x, y - 1);
        push(x, y + 1);
      }
    }
  }
  cout << ans << endl;

  return 0;
}