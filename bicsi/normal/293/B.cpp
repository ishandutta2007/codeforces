#include <bits/stdc++.h>

using namespace std;
const int kMod = 1e9 + 7;

void act(int& x, int y) {
  x += y;
  if (x >= kMod)
    x -= kMod;
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  if (n == 1 && m == 1) {
    cout << k << endl;
    return 0;
  }
  
  if (n + m - 1 > k) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
      v[i][j] -= 1;
    }
  }

  if (n < m) {
    vector<vector<int>> vt(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        vt[j][i] = v[i][j];
      }
    }
    swap(v, vt);
    swap(n, m);
  }
    
  int sc = v[0][0], ec = v[n - 1][m - 1];
  if (sc != -1 && ec != -1 && sc == ec) {
    cout << 0 << endl;
    return 0;
  }
  
  if (sc != -1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == 0 && j == 0) continue;
        if (v[i][j] == sc) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }
  
  if (ec != -1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == n - 1 && j == m - 1) continue;
        if (v[i][j] == ec) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }
  
  vector<int> remap(k, -1);
  int vals = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) continue;
      if (i == n - 1 && j == m - 1) continue;
      if (v[i][j] == -1) continue;

      if (remap[v[i][j]] == -1) 
        remap[v[i][j]] = vals++;
      v[i][j] = remap[v[i][j]];
    }
  }
  
  k -= 2;
  vector<int> pw(k + 1, 1);
  for (int i = 1; i <= k; ++i) 
    pw[i] = pw[i - 1] * (m + 1);
    
  auto trans = [&](int state, int c, int val) {
    int now = (state / pw[c]) % (m + 1);
    int delta = now - val;
    if (delta <= 0) return -1;
    return state - pw[c] * delta;
  };
  
  int max_state = pw[k];
  vector<int> dp(max_state, 0);
  dp[max_state - 1] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) continue;
      if (i == n - 1 && j == m - 1) continue;

      for (int state = 0; state < max_state; ++state) {
        if (dp[state]) {
          for (int c = 0; c < k; ++c) {
            if (v[i][j] != -1 && c != v[i][j]) continue;

            int to = trans(state, c, j);
            if (to != -1) act(dp[to], dp[state]);
          }
        }
        dp[state] = 0;
      }
    }
  }
  
  int res = 0;
  for (auto x : dp)
    act(res, x);
  
  if (ec == -1) {
    res = 1LL * res * (k + 1 - vals) % kMod;
    if (sc == -1)
      res = 1LL * res * (k + 2 - vals) % kMod;
  } else if (sc == -1) {
    res = 1LL * res * (k + 1 - vals) % kMod;
  }
  
  cout << res << endl;

  return 0;
}