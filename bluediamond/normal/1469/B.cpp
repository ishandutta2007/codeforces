#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = 100 + 7;
int n;
int m;
int a[N];
int b[N];
int dp[N][N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += a[i - 1];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
      b[i] += b[i - 1];
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dp[i][j] = 0;
        if (i - 1 >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
        if (j - 1 >= 0) {
          dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
        dp[i][j] = max(dp[i][j], a[i] + b[j]);
      }
    }

    cout << dp[n][m] << "\n";
  }

}