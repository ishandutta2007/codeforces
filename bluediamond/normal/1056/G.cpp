#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

#define op() {if (x < m) x += t; else x -= t; t--; x %= n; if (x < 0) x += n;}

const int N = (int) 1e5 + 7;
int cand[N];

signed realMain() {
  int n, m, x, t;
  cin >> n >> m >> x >> t; x--; inf:
  if (cand[x]) t = t % (cand[x] - t);
  cand[x] = t;
  if (t > n) {
    for (int i = 1; i <= n; i++) op(); goto inf;
  } else {
    while (t) op();
    cout << x + 1 << "\n";
  }
  return 0;
}