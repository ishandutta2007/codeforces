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

const int N = (int) 4e6 + 7;
int n, a[N], best, last[N], mx;
int m1[N], m2[N];

void upd(int i, int x) {
  if (x > m1[i]) {
    m2[i] = m1[i];
    m1[i] = x;
  } else {
    m2[i] = max(m2[i], x);
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  mx *= 2;
  mx = log2(mx);
  mx = (1 << mx);
  for (int i = 1; i <= n; i++) {
    upd(a[i], i);
  }
  for (int bit = 0; (1 << bit) < mx; bit++) {
    for (int mask = mx - 1; mask >= 0; mask--) {
      if (!(mask & (1 << bit))) {
        upd(mask, m1[mask + (1 << bit)]);
        upd(mask, m2[mask + (1 << bit)]);
      }
    }
  }

  for (int i = 1; i + 2 <= n; i++) {
    int cur = a[i], fight_for = (1 << 21) - 1 - a[i], ret = 0;
    for (int bit = 22; bit >= 0; bit--) {
      if ((ret + (1 << bit) < mx) && (fight_for & (1 << bit)) && (i + 1 <= m2[ret + (1 << bit)])) {
        ret += (1 << bit);
      }
    }
    best = max(best, cur + ret);
  }
  cout << best << "\n";
  return 0;
}