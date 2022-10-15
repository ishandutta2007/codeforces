#include <bits/stdc++.h>

using namespace std;

#define int long long
const int M = (int) 1e9 + 7;
int n, m, sol, lol;

int rep(int x) {
  x %= M;
  if (x < 0) x += M;
  return x;
}

int g(int x) {
  int a = x, b = x + 1;
  if (a % 2 == 0) a /= 2;
  else b /= 2;
  return rep(rep(a) * rep(b));
}

int g(int x, int y) {
  return rep(g(y) - g(x - 1));
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  lol = rep(n) * rep(m);
  m = min(n, m);
  int l = 1;
  while (l <= m) {
    int r = n / (n / l);
    r = min(r, m);
    sol = rep(sol + rep(n / l) * g(l, r));
    l = r + 1;
  }
  cout << rep(lol - sol) << "\n";

  return 0;
}