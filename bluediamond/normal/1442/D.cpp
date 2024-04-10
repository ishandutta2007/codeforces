#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3000 + 7;
int n;
int k;
vector<ll> a[N];
int len[N];
ll full[N];
ll sol = 0;
vector<ll> dp;
vector<vector<ll>> memory;

void upd(int len, ll val) {
  memory.push_back(dp);
  for (int t = k - len; t >= 0; t--) {
    dp[t + len] = max(dp[t + len], dp[t] + val);
  }
}

void undo() {
  dp = memory.back();
  memory.pop_back();
}

void run(int l, int r) {
  if (l == r) {
    for (int t = 0; t <= k; t++) {
      int rem = min(k - t, (int) a[l].size());
      if (rem > 0) {
        sol = max(sol, dp[t] + a[l][rem - 1]);
      }
    }
  } else {
    int m = (l + r) / 2;
    for (int j = m + 1; j <= r; j++) {
      upd(len[j], full[j]);
    }
    run(l, m);
    for (int j = m + 1; j <= r; j++) {
      undo();
    }
    for (int j = l; j <= m; j++) {
      upd(len[j], full[j]);
    }
    run(m + 1, r);
    for (int j = l; j <= m; j++) {
      undo();
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  dp.resize(k + 1, 0);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> len[i];
    a[i].resize(len[i]);
    for (int j = 0; j < len[i]; j++) {
      cin >> a[i][j];
      full[i] += a[i][j];
      a[i][j] = full[i];
    }
  }
  run(1, n);
  cout << sol << "\n";
}