#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int M = (int) 1e9 + 7;

int rep(int x) {
  x %= M;
  if (x < 0) x += M;
  return x;
}

int add(int a, int b) {
  a = rep(a);
  b = rep(b);
  return rep(a + b);
}

int mul(int a, int b) {
  a = rep(a);
  b = rep(b);
  return rep(a * b);
}

void addup(int &a, int b) {
  a = add(a, b);
}

int gauss(int x) {
  if (x % 2 == 0) return mul(x / 2, x + 1);
  return mul(x, (x + 1) / 2);
}

int a, b, sol;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);


  cin >> a >> b;


  sol = 0;
  for (int r = 1; r < b; r++) {
    int lo = r, hi = r * a + r - 1;

    if (lo > hi) continue;
    lo = (lo - 1) / r + 1;
    hi = hi / r;
    if (lo > hi) continue;
    int cur = 0;
    addup(cur, mul(b, add(gauss(hi), -gauss(lo - 1))));
    addup(cur, hi - lo + 1);
    addup(sol, mul(cur, r));
  }
  cout << sol << "\n";
  return 0;
}