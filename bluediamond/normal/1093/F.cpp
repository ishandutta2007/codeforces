#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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

const int N = (int) 1e5 + 7;
const int K = 100 + 7;
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

int n, mx, len, a[N], dp[N][K], tot[N], pre[N][K];
/// dp[i][j] = cnt good prefixes (1...i) so that the last element is equal to j

void baga(int i) {
  for (int j = 1; j <= mx; j++) {
    tot[i] = add(tot[i], dp[i][j]);
  }
}

int matches(int x, int l, int r) {
  return pre[r][x] + pre[r][0] - pre[l - 1][x] - pre[l - 1][0];
}

void calc(int i, int j) {
  dp[i][j] = tot[i - 1];
  /// le scad pe cele care doar acum se formeaza
  if (i >= len) {
    if (matches(j, i - len + 1, i) == len) {
    //  cout << i - len + 1 << "..." << i << " : " << j << "\n";
      int bad = add(tot[i - len], -dp[i - len][j]);
      if (i - len == 0) bad = 1;
      dp[i][j] = add(dp[i][j], -bad);
    }
  }
}

signed realMain() {
  cin >> n >> mx >> len;
  if (len == 1) {
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = max(a[i], 0LL);
    for (int j = 0; j <= mx; j++) pre[i][j] = pre[i - 1][j];
    pre[i][a[i]]++;
  }
  if (a[1] == 0) {
    for (int j = 1; j <= mx; j++) {
      dp[1][j] = 1;
    }
  } else {
    dp[1][a[1]] = 1;
  }
  baga(1);
  for (int i = 2; i <= n; i++) {
    if (a[i] == 0) {
      for (int j = 1; j <= mx; j++) calc(i, j);
    } else {
      calc(i, a[i]);
    }
    baga(i);
  }
  cout << tot[n] << "\n";
  return 0;
}