#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    return a - MOD;
  }
  if (a < 0) {
    return a + MOD;
  }
  return a;
}

int mul(int a, int b) {
  return a * (long long) b % MOD;
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
  return mul(a, pw(b, MOD - 2));
}

const int N = 200000 + 7;
int n, f[N];

int comb(int n, int k) {
  return dv(f[n], mul(f[k], f[n - k]));
}

int solve(int n, int k) {
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = mul(f[i - 1], i);
  }
  int colors = n - k, sol = 0;
  for (int c = 1; c <= colors; c++) {
    int now = comb(colors, c);
    now = mul(now, pw(c, n));
    sol = add(now, -sol);
  }
  sol = mul(comb(n, colors), sol);
  if (k > 0) {
    sol = mul(sol, 2);
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  if (k > n) {
    cout << "0\n";
  } else {
    cout << solve(n, k) << "\n";
  }
  return 0;
}