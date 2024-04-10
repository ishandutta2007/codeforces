#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e6 + 7;
int n;
int a[N], n1;
int b[N], n2;
bool from_a[N];

bool ok1(int k) {
  bool ok = 1;
  for (int i = 1; i <= k; i++) {
    ok &= (a[i] == min(a[i], b[n - k + i]));
  }
  return ok;
}

bool ok2(int k) {
  bool ok = 1;
  for (int i = k + 1; i <= n; i++) {
    ok &= (a[i] == max(a[i], b[i - k]));
  }
  return ok;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      from_a[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      from_a[x] = 1;
    }
    n1 = n2 = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (from_a[i]) {
        a[++n1] = i;
      } else {
        b[++n2] = i;
      }
    }
    assert(n1 == n && n2 == n);
    int l = 0, r = n, p1 = -(int) 1e9, p2 = (int) 1e9;
    while (l <= r) {
      int m = (l + r) / 2;
      if (ok1(m)) {
        p1 = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    l = 0, r = n;
    while (l <= r) {
      int m = (l + r) / 2;
      if (ok2(m)) {
        p2 = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << max(0, p1 - p2 + 1) << "\n";
  }


}