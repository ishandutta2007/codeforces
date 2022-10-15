#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int n, a[101], b[101];

bool ok(int total) {
  int cnt = total - total / 4, sa = 0;
  for (int i = 100; i >= 0; i--) {
    int take = min(cnt, a[i]);
    cnt -= take;
    sa += take * i;
  }
  ///cout << " = " << cnt << "\n";
  assert(cnt == 0);
  cnt = total - total / 4;
  int sb = 0;
  for (int i = 100; i >= 0; i--) {
    int take = min(cnt, b[i]);
    cnt -= take;
    sb += take * i;
  }
  assert(cnt == 0);
  return sa >= sb;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= 100; i++) a[i] = b[i] = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      a[x]++;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      b[x]++;
    }
    int sol = -1, l = 0, r = (int) 1e15;
    while (l <= r) {
      int m = (l + r) / 2;
      a[100] += m;
      b[0] += m;
      if (ok(n + m)) {
        sol = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
      a[100] -= m;
      b[0] -= m;
    }
    assert(sol != -1);
    cout << sol << "\n";
  }
}


/**

**/