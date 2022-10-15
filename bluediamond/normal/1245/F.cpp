#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll sum(int n, int m) {
  if (n < 0 || m < 0) {
    return 0;
  }
  if (n == 0 || m == 0) {
    return max(n, m) + 1;
  }
  ll sol = 0;
  for (int pn = 0; pn <= 30; pn++) {
    for (int pm = 0; pm <= 30; pm++) {
      bool bad = 0;
      if ((n & m) >> max(pn, pm) || (pn && (n & (1 << (pn - 1))) == 0) || (pm && (m & (1 << (pm - 1))) == 0)) {
        continue;
      }
      ll adun = 1;
      for (int i = 0; i <= 30; i++) {
        if (i == pn - 1) {
          if (i < pm - 1) {
            adun *= 2;
          }
          continue;
        }
        if (i == pm - 1) {
          if (i < pn - 1) {
            adun *= 2;
          }
          continue;
        }
        if (i >= pn && i >= pm) {
          continue;
        }
        if (i >= pn && i < pm) {
          if (!(n & (1 << i))) {
            adun *= 2;
          }
          continue;
        }
        if (i >= pm && i < pn) {
          if (!(m & (1 << i))) {
            adun *= 2;
          }
          continue;
        }
        if (i < pm && i < pm) {
          adun *= 3;
          continue;
        }
        assert(0);
      }

      sol += adun;
    }
  }
  return sol;
}

ll f(int l, int r) {
  return sum(r, r) - 2 * sum(l - 1, r) + sum(l - 1, l - 1);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    ll x = f(l, r);
    cout << x << "\n";
  }

}