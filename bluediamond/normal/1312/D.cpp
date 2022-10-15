#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

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

const int N = (int) 2e5 + 7;
int f[N], ii[N];

int c(int n, int k) {
  if (n >= k) {
    return mul(f[n], mul(ii[k], ii[n - k]));
  } else {
    return 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mul(f[i - 1], i);
  }
  ii[N - 1] = dv(1, f[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ii[i] = mul(ii[i + 1], i + 1);
  }
  int n, m, sol = 0;
  cin >> n >> m;
  if (n == 2) {
    cout << "0\n";
    return 0;
  }
  for (int mx = 1; mx <= m; mx++) {
    sol = add(sol, mul(c(mx - 1, n - 2), pw(2, n - 3)));
  }
  sol = mul(sol, n - 2);
  cout << sol << "\n";

}