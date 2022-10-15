#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;

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


signed realMain() {
  int x, k;
  cin >> x >> k;
  if (x == 0) {
    cout << "0\n";
    return 0;
  }
  if (k == 0) {
    cout << mul(2, x % M) << "\n";
    return 0;
  }
  x = add(mul(2, x % M), -1);
  x = mul(x, pw(2, k));
  x = add(x, 1);
  cout << x << "\n";
  return 0;
}