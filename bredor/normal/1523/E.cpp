#include "bits/stdc++.h"

using namespace std;

const int M = 148800;
const int mod = 1'000'000'007;

typedef long long ll;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int mul(ll x, ll y) {
  return x * y % mod;
}

int bin(int x, int to) {
  int y = 1;
  while (to) {
    if (to & 1)
      y = mul(y, x);
    x = mul(x, x);
    to >>= 1;
  }
  return y;
}

int inv(int x) {
  return bin(x, mod - 2);
}

int n, k;
int f[M], fi[M];

void calc() {
  f[0] = 1;
  for (int i = 1; i < M; ++i) {
    f[i] = mul(i, f[i - 1]);
  }

  for (int i = 0; i < M; ++i) {
    fi[i] = inv(f[i]);
  }
}

int binom(int n, int k) {
  if (k < 0 || n < 0 || n < k)
    return 0;
  return mul(f[n], mul(fi[k], fi[n - k]));
}

void solve() {
  cin >> n >> k;

  int ans = 1;
  for (int i = 1; (i - 1) * (k - 1) <= n && i <= n; ++i) {
    int r = n - (i - 1) * (k - 1);
    int cur = mul(binom(r, i), f[i]);
    cur = mul(cur, mul(fi[n], f[n - i]));
    ans = add(ans, cur);
  }

  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  calc();
  while (t--) {
    solve();
  }
  return 0;
}