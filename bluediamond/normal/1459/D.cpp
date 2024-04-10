#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
const int INF = (int) 1e9;
int n;
int a[N], b[N];
int dp[N][N * N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i] >> a[i];
    A += a[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N * N; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    for (int x = last; x >= 0; x--) {
      for (int c = i - 1; c >= 0; c--) {
        dp[c + 1][x + b[i]] = max(dp[c + 1][x + b[i]], dp[c][x] + a[i]);
      }
    }
    last += b[i];
  }

  for (int k = 1; k <= n; k++) {
    int sol = 0;
    for (int b = 0; b <= last; b++) {
      sol = max(sol, min(2 * b, dp[k][b] + A));
    }
    cout << fixed << setprecision(9) << sol * 0.5 << " ";
  }
  cout << "\n";

}