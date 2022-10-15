#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    return a - mod;
  }
  if (a < 0) {
    return a + mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, mod - 2));
}

int sqr(int a) {
  return mul(a, a);
}

const int N = 1000 + 7;
const int K = 1000000 + 7;
int dp[N][N], f[K], inv[K];

int c(int n, int k) {
  int x = f[n];
  int y = mul(inv[k], inv[n - k]);
  return mul(x, y);
}

void build() {
  f[0] = dp[0][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = add(mul(j, dp[i - 1][j]), dp[i - 1][j - 1]);
    }
  }
  for (int i = 1; i < K; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[K - 1] = dv(1, f[K - 1]);
  for (int i = K - 2; i >= 0; i--) {
    inv[i] = mul(inv[i + 1], i + 1);
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  build();
  int n, m, k;
  cin >> n >> m >> k;
  if (m == 1) {
    cout << pw(k, n) << "\n";
    return 0;
  }
  int sol = 0;
  for (int x = 0; x <= n; x++) {
    for (int y = 0; y <= x; y++) {
      if (2 * x - y <= k) {
        int a = mul(c(k, x - y), mul(c(k - (x - y), x - y), c(k - 2 * (x - y), y)));
        int b = pw(y, n * (m - 2));
        int c = sqr(mul(dp[n][x], f[x]));
        int p = mul(a, mul(b, c));
        sol = add(sol, p);
      }
    }
  }
  cout << sol << "\n";
}