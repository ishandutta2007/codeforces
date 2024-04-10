#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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

const int N = 2000 + 7;
int len, n, k, ff[N], ss[N], val[N][N], pay1[N], pay2[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
  int sa = a.first + a.second, sb = b.first + b.second;
  return sa < sb;
}

signed realMain() {
  cin >> len >> n >> k;
  len = len - k + 1;
  vector<pair<int, int>> v(n);
  for (auto &x : v) cin >> x.first >> x.second;
  sort(v.begin(), v.end(), cmp);
  for (int i = 1; i <= n; i++) {
    ff[i] = v[i - 1].first;
    ss[i] = v[i - 1].second;
  }
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= n; j++) {
      int lmax = max(ff[j], i), rmin = min(ss[j], i + k - 1);
      if (lmax <= rmin) {
        val[i][j] = rmin - lmax + 1;
        pay2[i] += val[i][j];
      }

    }
  }
  int ret = 0;
  for (int pre = 0; pre <= n; pre++) {
    if (pre) {
      for (int i = 1; i <= len; i++) {
        pay1[i] += val[i][pre];
        pay2[i] -= val[i][pre];
      }
    }
    int mx1 = 0, mx2 = 0;
    for (int i = 1; i <= len; i++) {
      mx1 = max(mx1, pay1[i]);
      mx2 = max(mx2, pay2[i]);
    }
    ret = max(ret, mx1 + mx2);
  }
  cout << ret << "\n";
  return 0;
}