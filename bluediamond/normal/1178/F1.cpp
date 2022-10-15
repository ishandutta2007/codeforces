#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int mul(int a, int b, int c) {
  return mul(a, mul(b, c));
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
  return mul(a, pw(b, M - 2));
}

const int N = 500 + 7;
int n, m, dp[N][N], mn[N][N];
int c[N], pos[N];

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    pos[c[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    mn[i][i] = c[i];
    for (int j = i + 1; j <= n; j++) {
      mn[i][j] = min(mn[i][j - 1], c[j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      dp[i][j] = 1;
    }
  }
  for (int l = n; l >= 1; l--) {
    for (int r = l; r <= n; r++) {
      /// dp[l][r] = ?
      int x = mn[l][r], p = pos[x], a = 0, b = 0;
      for (int f = l; f <= p; f++) {
        int bag = 1;
        bag = mul(bag, dp[f][p - 1]);
        bag = mul(bag, dp[l][f - 1]);
        a = add(a, bag);
      }
      for (int s = p; s <= r; s++) {
        int bag = 1;
        bag = mul(bag, dp[p + 1][s]);
        bag = mul(bag, dp[s + 1][r]);
        b = add(b, bag);
      }
      dp[l][r] = mul(a, b);
    }
  }

  cout << dp[1][n] << "\n";
  return 0;
}