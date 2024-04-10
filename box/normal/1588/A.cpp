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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n; i++)
      cin >> b[i];
    sort(all(b));
    bool ok = 1;
    for (int i = 0; i < n; i++)
      ok = ok && ((a[i] == b[i]) || (a[i] + 1 == b[i]));
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}