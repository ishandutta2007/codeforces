#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

ll pre(ll x) {
  ll p = 1;
  while (p * 10 <= x) p *= 10;
  ll ret = min(p, x - p + 1);
  p /= 10;
  while (p) ret += p, p /= 10;
  return ret;
}

ll get(ll l, ll r) {
  return pre(r) - pre(l - 1);
}

const int N = 2000 + 7;
ld prob[N], p[N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k; cin >> n;
  for (int i = 1; i <= n; i++) {
    ll l, r; cin >> l >> r;
    ld alpha = get(l, r), beta = r - l + 1;
    prob[i] = alpha / beta;
  }
  cin >> k;
  /// n * k / 100
  if (n * k % 100 == 0) k = n * k / 100; else k = n * k / 100 + 1;

  p[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i][0] = p[i - 1][0] * (1 - prob[i]);
    for (int j = 1; j < n; j++) {
      p[i][j] = p[i - 1][j] * (1 - prob[i]) + p[i - 1][j - 1] * prob[i];
    }
    p[i][n] = p[i - 1][n] + p[i - 1][n - 1] * prob[i];
  }
  ld sol = 0;
  for (int j = k; j <= n; j++) {
    sol += p[n][j];
  }
  cout << fixed << setprecision(9) << sol << "\n";
}