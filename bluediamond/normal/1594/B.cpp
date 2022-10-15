#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int M = (int) 1e9 + 7;

int rep(int x) {
  x %= M;
  if (x < 0) x += M;
  return x;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, k, sol = 0, coef = 1;
    cin >> n >> k;
    for (int i = 0; (1 << i) <= k; i++) {
      if (k & (1 << i)) {
        sol = rep(sol + coef);
      }
      coef = rep(coef * n);
    }
    cout << sol << "\n";

  }

  return 0;
}