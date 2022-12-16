#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 505;
const int INF = 0x3f3f3f3f;
int dp[N][N][N];
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, x;
    cin >> n >> x;
    for (int i=0; i<=n; ++i) {
      for (int j=0; j<N; ++j) {
        for (int q=0; q<N; ++q) {
          dp[i][j][q] = INF;
        }
      }
    }
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
    }
    dp[0][0][x] = 0;
    for (int i=1; i<=n; ++i) {
      for (int j=0; j<N; ++j) {
        for (int q=0; q<N; ++q) {
          if (j == a[i]) {
            // don't do a swap
            for (int k=0; k<=j; ++k) {
              dp[i][j][q] = min(dp[i][j][q], dp[i-1][k][q]);
            }
          }
          if (j < q && q == a[i]) {
            // do a swap;
            for (int k=0; k<=j; ++k) {
              dp[i][j][q] = min(dp[i][j][q], dp[i-1][k][j]+1);
            }
          }
        }
      }
    }
    int ans = INF;
    for (int j=0; j<N; ++j) {
      for (int q=0; q<N; ++q) {
        ans = min(ans, dp[n][j][q]);
      }
    }
    if (ans == INF) {
      cout << -1 << "\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}