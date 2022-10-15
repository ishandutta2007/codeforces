#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2 * 2000 + 7;
const int INF = (int) 1e9;
int n, a[N], dp[N][N][2];

void upd(int i, int j, int k, int x) {
  dp[i][j][k] = min(dp[i][j][k], x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n;
    cin >> n;
    n *= 2;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k <= 1; k++) dp[i][j][k] = INF;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int c0 = 0; c0 <= n / 2; c0++) {
      for (int c1 = 0; c1 <= n / 2; c1++) {
        if (c0 == n / 2 && c1 == n / 2) break;
        int x = a[c0 + c1 + 1];
        /// ant = 0, now = 0
        upd(c0 + 1, c1, 0, max(dp[c0][c1][0], x));
        /// ant = 0, now = 1
        if (x > dp[c0][c1][0]) {
          upd(c0, c1 + 1, 1, x);
        }
        /// ant = 1, now = 0
        if (x > dp[c0][c1][1]) {
          upd(c0 + 1, c1, 0, x);
        }
        /// ant = 1, now = 1
        upd(c0, c1 + 1, 1, max(dp[c0][c1][1], x));
      }
    }
    if (dp[n / 2][n / 2][0] != INF || dp[n / 2][n / 2][1] != INF) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}