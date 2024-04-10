#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = (int) 1e6 + 7;
const int K = 22;
int n, k, dp[N][K][2];

int cnt(int p2, int p3) {
  return n / ((1 << p2) * (p3 ? 3 : 1));
}

signed main() {
  cin >> n;
  k = log2(n);
  dp[1][k][0] = 1;
  if ((1 << (k - 1)) * 3 <= n) dp[1][k - 1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int p2 = 0; p2 <= k; p2++) {
      for (int p3 = 0; p3 <= 1; p3++) {
        if (!dp[i][p2][p3]) continue;
        dp[i + 1][p2][p3] = add(dp[i + 1][p2][p3], mul(cnt(p2, p3) - i, dp[i][p2][p3]));
        if (p2) dp[i + 1][p2 - 1][p3] = add(dp[i + 1][p2 - 1][p3], mul(cnt(p2 - 1, p3) - cnt(p2, p3), dp[i][p2][p3]));
        if (p3) dp[i + 1][p2][p3 - 1] = add(dp[i + 1][p2][p3 - 1], mul(cnt(p2, p3 - 1) - cnt(p2, p3), dp[i][p2][p3]));
      }
    }
  }
  cout << dp[n][0][0] << "\n";
}