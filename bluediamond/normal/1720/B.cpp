#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
const ll INF = (ll) 1e18 + 7;
int n;
ll a[N], mx_pref[N], mn_pref[N], mx_suf[N], mn_suf[N], x[N], y[N];

signed main() {
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

 /// freopen ("___input___.txt", "r", stdin);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    ll sol = *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1);
    for (int iter = 0; iter < 2; iter++) {
      mx_pref[0] = -INF;
      mn_pref[0] = +INF;
      for (int i = 1; i <= n; i++) {
        mx_pref[i] = max(mx_pref[i - 1], a[i]);
        mn_pref[i] = min(mn_pref[i - 1], a[i]);
      }
      mx_suf[n + 1] = -INF;
      mn_suf[n + 1] = +INF;
      for (int i = n; i >= 1; i--) {
        mx_suf[i] = max(mx_suf[i + 1], a[i]);
        mn_suf[i] = min(mn_suf[i + 1], a[i]);
      }
      for (int i = 1; i <= n; i++) x[i] = -a[i]; for (int j = 1; j <= n; j++) y[j] = a[j] + mx_suf[j + 1] - mn_suf[j + 1];
      for (int i = n - 1; i >= 1; i--) y[i] = max(y[i + 1], y[i]);
      for (int i = 1; i <= n; i++) {
        sol = max(sol, x[i] + y[i]);
      }

      for (int i = 1; i <= n; i++) x[i] = -a[i] + mx_pref[i - 1] - mn_pref[i - 1]; for (int j = 1; j <= n; j++) y[j] = a[j];
      for (int i = n - 1; i >= 1; i--) y[i] = max(y[i + 1], y[i]);
      for (int i = 1; i <= n; i++) {
        sol = max(sol, x[i] + y[i]);
      }

      for (int i = 1; i <= n; i++) x[i] = -a[i] + mx_pref[i - 1]; for (int j = 1; j <= n; j++) y[j] = a[j] - mn_suf[j + 1];
      for (int i = n - 1; i >= 1; i--) y[i] = max(y[i + 1], y[i]);
      for (int i = 1; i <= n; i++) {
        sol = max(sol, x[i] + y[i]);
      }

      for (int i = 1; i <= n; i++) x[i] = -a[i] - mn_pref[i - 1]; for (int j = 1; j <= n; j++) y[j] =a[j] + mx_suf[j + 1];
      for (int i = n - 1; i >= 1; i--) y[i] = max(y[i + 1], y[i]);
      for (int i = 1; i <= n; i++) {
        sol = max(sol, x[i] + y[i]);
      }

      reverse(a + 1, a + n + 1);
    }
    cout << sol << "\n";
  }

  return 0;
}