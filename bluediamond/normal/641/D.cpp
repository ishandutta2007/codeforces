#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e5 + 7;
int n;
double mx[N], mn[N], pref_a[N], pref_b[N];
signed main() { ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> mx[i];
  for (int i = 1; i <= n; i++) cin >> mn[i];
  for (int i = 1; i <= n; i++) mx[i] += mx[i - 1];
  for (int i = n; i >= 1; i--) mn[i] += mn[i + 1];
  for (int i = 1; i <= n; i++) {
    double s = 1 +  mx[i] - mn[i + 1], p = mx[i], delta = max((double) 0, s * s - 4 * p);
    pref_a[i] = (s + sqrt(delta)) / 2;
    pref_b[i] = s - pref_a[i];
  }
  for (int i = 1; i <= n; i++) cout << pref_a[i] - pref_a[i - 1] << " "; cout << "\n";
  for (int i = 1; i <= n; i++) cout << 1 +  mx[i] - mn[i + 1] - pref_a[i] - pref_b[i - 1] << " "; cout << "\n";
}