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

const int N = (int) 2e5 + 7;
int n, l[N], r[N], p[N];
int ret;

int pdif(int l1, int r1, int l2, int r2) {
  int lmax = max({l1, l2}), rmin = min({r1, r2}), com = max(0, rmin - lmax + 1);
  int prod_len = mul(r1 - l1 + 1, r2 - l2 + 1);
  return add(1, -dv(com, prod_len));
}

int pdif(int l1, int r1, int l2, int r2, int l3, int r3) {
  int ret = 0;
  int com13 = min({r1, r2, r3}) - max({l1, l2, l3}) + 1;
  int com1 = min({r1, r2}) - max({l1, l2}) + 1;
  int com3 = min({r2, r3}) - max({l2, l3}) + 1;
  com13 = max(0, com13);
  com1 = max(0, com1);
  com3 = max(0, com3);

  ret = add(ret, mul(com13, mul(dv(r3 - l3, r3 - l3 + 1), dv(r1 - l1, r1 - l1 + 1))));
  ret = add(ret, mul(com1 - com13, dv(r1 - l1, r1 - l1 + 1)));
  ret = add(ret, mul(com3 - com13, dv(r3 - l3, r3 - l3 + 1)));
  ret = add(ret, r2 - l2 + 1 - (com13 + com1 + com3 - com13 - com13));


  ret = dv(ret, r2 - l2 + 1);
  return ret;
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    p[i] = pdif(l[i - 1], r[i - 1], l[i], r[i]);
  }
  int ciu = 0;
  for (int i = 1; i <= n; i++) {
    ret = add(ret, mul(p[i], ciu));
    if (i - 1 >= 1) {
      ciu = add(ciu, p[i - 1]);
      ret = add(ret, pdif(l[i - 2], r[i - 2], l[i - 1], r[i - 1], l[i], r[i]));
    }
  }

  ret = mul(ret, 2);
  for (int i = 1; i <= n; i++) {
    ret = add(ret, p[i]);
  }
  if (home) {
    assert(ret == 116666753);
  }
  cout << ret << "\n";
  return 0;
}