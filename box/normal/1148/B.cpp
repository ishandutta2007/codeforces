#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    a[i] += ta;
  vector<ll> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];
  if (k >= n) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = -1;
  int h = 0;
  for (int i = 0; i <= k; i++) {
    while (h != m && b[h] < a[i])
      h++;
    if (h + (k - i) >= m) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, b[h + k - i]);
  }
  cout << ans + tb << endl;
}