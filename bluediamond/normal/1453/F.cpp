#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3000 + 7;
int n, a[N], dp[N][N];
/// dp[i][k] = am un singur drum de la 1 la i si exista o singura solutie pt un salt >= k

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
      for (int j = i; j <= n; j++) dp[i][j] = (int) 1e9;
      int cnt = 0;
      for (int j = i - 1; j >= 1; j--) {
        if (a[j] + j >= i) {
          dp[i][a[j] + j] = min(dp[i][a[j] + j], dp[j][i - 1] + cnt);
          cnt++;
        }
      }
      for (int j = i + 1; j <= n; j++) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
    cout << dp[n][n] << "\n";
  }


}