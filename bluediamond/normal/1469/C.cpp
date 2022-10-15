#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = (int) 2e5 + 7;
int n;
int k;
int h[N];
int p[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> h[i];
    }
    bool ok = 1;
    p[1] = h[1];
    p[n] = h[n];
    for (int i = 2; i < n; i++) {
      int mn = max(h[i], p[i - 1] - k + 1), mx = min(h[i] + k - 1, p[i - 1] + k - 1);
      ok &= (mn <= mx);
      if (h[i] < h[i + 1]) {
        p[i] = mx;
      } else {
        p[i] = mn;
      }
    }
    ok &= (h[1] == p[1] && h[n] == p[n]);
    for (int i = 1; i <= n; i++) {
      ok &= (h[i] <= p[i] && p[i] < h[i] + k);
    }
    for (int i = 1; i < n; i++) {
      ok &= (abs(p[i] - p[i + 1]) < k);
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}