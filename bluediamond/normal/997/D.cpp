#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
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
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void baga(int &a, int x) {
  a = add(a, x);
}

const int N = 4000 + 7;
const int K = 80;
int n[2], kk, ret[2][N][K], f[N], s[N];
vector<int> g[2][N];
int sz[N];
map<int, int> dp[K][N];
int fact[N], ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed realMain() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  cin >> n[0] >> n[1] >> kk;
  for (int it = 0; it < 2; it++) {
    for (int i = 1; i <= n[it]; i++) {
      g[it][i].push_back(0);
    }
    for (int i = 1; i < n[it]; i++) {
      int x, y;
      cin >> x >> y;
      g[it][x].push_back(y);
      g[it][y].push_back(x);
    }
  }
  for (int it = 0; it < 2; it++) {
    for (int k = 0; k <= kk; k++) {
      for (int i = 1; i <= n[it]; i++) {
        dp[k][i].clear();
      }
    }
    for (int i = 1; i <= n[it]; i++) {
      for (auto &j : g[it][i]) {
        dp[0][i][j] = 1;
      }
    }
    for (int k = 2; k <= kk; k += 2) {
      for (int i = 1; i <= n[it]; i++) {
        for (int k2 = 0; 2 + k2 <= k; k2++) {
          int sum = 0;
          for (auto &oth : g[it][i]) {
            baga(sum, dp[k2][oth][i]);
          }
          for (auto &j : g[it][i]) {
            int rl = sum;
            if (j) rl = add(rl, -dp[k2][j][i]);
            baga(dp[k][i][j], mul(rl, dp[k - k2 - 2][i][j]));
          }
        }
      }
    }
    for (int i = 1; i <= n[it]; i++) {
      for (int k = 0; k <= kk; k += 2) {
        ret[it][i][k] = dp[k][i][0];
      }
    }
  }
  int sol = 0;
  for (int from0 = 0; from0 <= kk; from0++) {
    int lol = 0, kek = 0;
    for (int v0 = 1; v0 <= n[0]; v0++) {
      kek = add(kek, ret[0][v0][from0]);
    }
    for (int v1 = 1; v1 <= n[1]; v1++) {
      lol = add(lol, ret[1][v1][kk - from0]);
    }
    baga(sol, mul(mul(lol, kek), comb(kk, from0)));
  }
  cout << sol << "\n";
  return 0;
}