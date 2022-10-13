#include <bits/stdc++.h>
 
using namespace std;

vector<vector<int>> pref, r;
vector<string> out_init;
 
bool check(int x, vector<string>& v, bool output) {
  int n = v.size(), m = v[0].size();
  for (int i = 0; i < n; ++i) {
    fill(pref[i].begin(), pref[i].end(), 0);
    fill(r[i].begin(), r[i].end(), 0);
    fill(out_init[i].begin(), out_init[i].end(), '.');
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j] == '.') pref[i][j] += 1;
      if (i > 0) pref[i][j] += pref[i - 1][j];
      if (j > 0) pref[i][j] += pref[i][j - 1];
      if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
    }
  }

  auto try_place = [&](int i, int j) {
    if (i - x < 0 || j - x < 0 || i + x >= n || j + x >= m)
      return false;
    int s = pref[i + x][j + x];
    if (i - x > 0) s -= pref[i - x - 1][j + x];
    if (j - x > 0) s -= pref[i + x][j - x - 1];
    if (i - x > 0 && j - x > 0) s += pref[i - x - 1][j - x - 1];
    if (s > 0)
      return false;
    // cerr << "PLACING: " << i << " " << j << endl;
    out_init[i][j] = 'X';
    r[i - x][j - x] += 1;
    if (i + x + 1 < n) r[i + x + 1][j - x] -= 1;
    if (j + x + 1 < m) r[i - x][j + x + 1] -= 1;
    if (i + x + 1 < n && j + x + 1 < m) r[i + x + 1][j + x + 1] += 1;

    return true;
  };
 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      try_place(i, j);
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i > 0) r[i][j] += r[i - 1][j];
      if (j > 0) r[i][j] += r[i][j - 1];
      if (i > 0 && j > 0) r[i][j] -= r[i - 1][j - 1];

      if (r[i][j] == 0 && v[i][j] == '.') continue;
      if (r[i][j] > 0 && v[i][j] == 'X') continue;
      return false;
    }
  }
  
  if (output) {
    for (int i = 0; i < n; ++i) {
      cout << out_init[i] << '\n';
    }
  }
  return true;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
 
  // check(1, v, true);
  
  out_init.resize(n, string(m, '.'));
  r.resize(n, vector<int>(m, 0));
  pref = r;

  int ans = 0;
  for (int step = (1 << 10); step; step /= 2) {
    if (ans + step > n && ans + step > m) continue;
    if (check(ans + step, v, false)) {
      ans += step;
    }
  }
  cout << ans << '\n';
  check(ans, v, true);
  
  return 0;
}