#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, m, q, r[N], c[N], down[N], up[N], mxsuf[N];

bool oke(int first) {
  for (int i = 1; i <= n; i++) {
    down[i] = (int) 1e9;
    up[i] = -(int) 1e9;
  }
  for (int i = 1; i <= first; i++) {
    int x = (r[i] + 1) / 2, y = (c[i] + 1) / 2;
    if (r[i] % 2 == 1) {
      /// it forces to go down
      down[x] = min(down[x], y);
    } else {
      /// it forces to go up
      up[x] = max(up[x], y);
    }
  }
  mxsuf[n] = up[n];
  for (int i = n - 1; i >= 1; i--) {
    mxsuf[i] = max(mxsuf[i + 1], up[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (down[i] <= mxsuf[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= q; i++) {
    cin >> r[i] >> c[i];
  }
  int sol = 0, l = 1, r = q;
  while (l <= r) {
    int m = (l + r) / 2;
    if (oke(m)) {
      sol = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  for (int i = 1; i <= sol; i++) {
    cout << "YES\n";
  }
  for (int i = 1; i <= q - sol; i++) {
    cout << "NO\n";
  }
  return 0;
}