#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
const ll INF = (ll) 1e18 + 7;
int pos[N];
int dim;
ll dp[N][N];

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int te;
  cin >> te;
  for (int tc = 1; tc <= te; tc++) {
    int n;
    ll x, y, cost = 0;
    string s, t;
    cin >> n >> x >> y >> s >> t;
    /// x >= y
    assert((int) s.size() == n);
    assert((int) t.size() == n);
    int balance = 0;
    for (int i = 0; i < n; i++) {
      balance += s[i] - '0';
      balance += t[i] - '0';
    }
    if (balance & 1) {
      cout << "-1\n";
      continue;
    }
    vector<bool> need(n, 0);
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        need[i] = 1;
      }
    }
    if (x >= y) {
      x = min(x, 2 * y);
      for (int i = 0; i + 2 < n; i++) {
        if (need[i] && need[i + 1] && need[i + 2]) {
          need[i] = need[i + 2] = 0;
          cost += y;
        }
      }

      for (int i = 0; i + 1 < n; i++) {
        if (need[i] && need[i + 1]) {
          for (int j = 0; j < n; j++) {
            if (need[j] && j != i && j != i + 1) {
              assert(abs(i - j) > 1);
              assert(abs(i + 1 - j) > 1);
              need[i] = need[j] = 0;
              cost += y;
              break;
            }
          }
        }
      }
      int prs = 0, sg = 0;
      for (int i = 0; i + 1 < n; i++) {
        if (need[i] && need[i + 1]) {
          prs++;
        }
      }
      for (int i = 0; i < n; i++) {
        if (need[i]) {
          sg++;
        }
      }

      cost += prs * x;
      cost += (sg - 2 * prs) / 2 * y;

      cout << cost << "\n";
    } else {
      /// x < y
      dim = 0;
      for (int i = 0; i < n; i++) {
        if (need[i]) {
          pos[++dim] = i;
        }
      }
      for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
          dp[i][j] = INF;
        }
      }
      dp[0][0] = 0;
      for (int i = 0; i <= dim; i++) {
        if (i + 1 <= dim) {
          for (int j = 0; j <= dim; j++) {
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            if (j >= 1) {
              dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + y);
            }
          }
        }
        if (i + 2 <= dim) {
          for (int j = 0; j <= dim; j++) {
            dp[i + 2][j] = min(dp[i + 2][j], dp[i][j] + min(y, x * (pos[i + 2] - pos[i + 1])));
          }
        }
      }
      /// cost += min(y, x * (bi - bj));

      cout << dp[dim][0] << "\n";
    }

  }
}