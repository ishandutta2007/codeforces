#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int cnt_rw, n;
  cin >> cnt_rw >> n;
  vector<vector<pair<int, int>>> what(cnt_rw, vector<pair<int, int>> (n));
  for (auto &v : what) {
    int cnt;
    cin >> cnt;
    for (int iter = 0; iter < cnt; iter++) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      for (int j = l; j <= r; j++) {
        v[j] = {l, r};
      }
    }
  }
  vector<vector<int>> dp(n, vector<int> (n, 0));
  for (int l = n - 1; l >= 0; l--) {
    for (int r = l; r <= n - 1; r++) {
      for (int k = l; k <= r; k++) {
        int cnt = 0;
        for (int i = 0; i < cnt_rw; i++) {
          cnt += (l <= what[i][k].first && what[i][k].second <= r);
        }
        int relax = cnt * cnt;
        if (l <= k - 1) relax += dp[l][k - 1];
        if (k + 1 <= r) relax += dp[k + 1][r];
        dp[l][r] = max(dp[l][r], relax);
      }
    }
  }
  cout << dp[0][n - 1] << "\n";
  return 0;
}