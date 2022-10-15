#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int long long
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
int n, m, a[N], ret, lft[N], t[N], scad;

int root(int x) {
  if (t[x] == x) {
    return x;
  } else {
    return t[x] = root(t[x]);
  }
}

void solve() {
  scad = 0;
  for (int j = 1; j <= n; j++) {
    lft[j] = j;
    t[j] = j;
  }
  for (int j = 1; j <= m; j++) {
    int pos = -1;
    int l = 1, r = n;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (lft[root(mid)] >= a[j] + 1 + scad) {
        r = mid - 1;
        if (lft[root(mid)] == a[j] + 1 + scad) {
          pos = mid;
        }
      } else {
        l = mid + 1;
      }
    }
    scad++;
    if (pos == -1) {
      continue;
    }
    int last = pos, lo = pos, hi = n;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (root(mid) == root(pos)) {
        last = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    lft[pos]++;
    if (last + 1 <= n && lft[last + 1] - scad == lft[pos] - scad) {
      t[last + 1] = pos;
    }
  }
  for (int j = 1; j <= n; j++) {
    ret -= max(1LL, lft[root(j)] - scad - 1);
  }
  for (int j = 1; j <= m; j++) {
    a[j] = n + 1 - a[j];
  }
}

signed realMain() {
  cin >> n >> m;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  ret = n * (n + 2);
  for (int j = 1; j <= m; j++) {
    cin >> a[j];
  }
  solve();
  solve();
  cout << ret << "\n";
  return 0;
}