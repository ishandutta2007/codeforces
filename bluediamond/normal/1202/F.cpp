#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

int a, b, n, ret, k1 = 1;

signed realMain() {
  cin >> a >> b;
  n = a + b;
  while (k1 <= n) {
    int g = n / k1;
    int k2 = n / g;
    int f1 = (a + g) / (g + 1), s1 = a / g;
    int f2 = (b + g) / (g + 1), s2 = b / g;
    if (f1 <= s1 && f2 <= s2) {
      int kmin = f1 + f2, kmax = s1 + s2;
      kmin = max(kmin, k1);
      kmax = min(kmax, k2);
      if (kmin <= kmax) {
        ret += kmax - kmin + 1;
      }
    }
    k1 = k2 + 1;
  }
  cout << ret << "\n";
  return 0;
}