#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<int>> XY(const vector<vector<int>>& v) {
  int n = v.size(), m = v[0].size();
  vector<int> X, Y;
  for (int i = 0; i < n; ++i) {
    int maxx = v[i][0];
    for (int j = 1; j < m; ++j) 
      maxx = max(maxx, v[i][j]);
    X.push_back(maxx);
  }
  for (int i = 0; i < m; ++i) {
    int maxx = v[0][i];
    for (int j = 0; j < n; ++j) 
      maxx = max(maxx, v[j][i]);
    Y.push_back(maxx);
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  return {X, Y};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
    }
  }

  auto [X, Y] = XY(v);
  // cerr << "XY: " << endl;
  // for (auto x : X) cerr << x << " "; cerr << endl;
  // for (auto x : Y) cerr << x << " "; cerr << endl;
  // cerr << endl;

  vector<pair<int, int>> free;
  vector<vector<int>> ans(n, vector<int>(m, -1));
  int ri = n - 1, cj = m - 1, at = 0;
  for (int val = n * m; val >= 1; --val) {
    bool max_row = (X.size() && X.back() == val);
    bool max_col = (Y.size() && Y.back() == val);
    if (max_row && max_col) {
      ans[ri][cj] = val;
      X.pop_back();
      Y.pop_back();
      for (int i = ri + 1; i < n; ++i)
        free.emplace_back(i, cj);
      for (int j = cj + 1; j < m; ++j)
        free.emplace_back(ri, j);
      --ri; --cj;
    } else if (max_row) {
      ans[ri][cj + 1] = val;
      X.pop_back();
      for (int j = cj + 2; j < m; ++j)
        free.emplace_back(ri, j);
      --ri;
    } else if (max_col) {
      ans[ri + 1][cj] = val;
      Y.pop_back();
      for (int i = ri + 2; i < n; ++i) 
        free.emplace_back(i, cj);
      --cj;
    } else {
      assert(at < (int)free.size());
      ans[free[at].first][free[at].second] = val;
      at += 1;
    }


    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     cout << ans[i][j] << " ";
    //   }
    //   cout << '\n';
    // }
    // cout << endl << endl;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  assert(XY(ans) == XY(v));

  return 0;
}