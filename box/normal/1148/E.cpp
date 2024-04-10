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
  int n;
  cin >> n;
  vector<pii> a(n), b(n);
  for (int i = 0; i < n; i++)
    a[i].se = b[i].se = i;
  for (int i = 0; i < n; i++)
    cin >> a[i].fi;
  for (int i = 0; i < n; i++)
    cin >> b[i].fi;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> dts(n);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    dts[i] = b[i].fi - a[i].fi;
    s += dts[i];
    if (s < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (s != 0) {
    cout << "NO" << endl;
    return 0;
  }
  stack<pii> contr;
  vector<pair<pii, int>> ops;
  for (int i = 0; i < n; i++) {
    if (dts[i] > 0)
      contr.push({a[i].se, dts[i]});
    else {
      int g = -dts[i];
      while (g) {
        auto [p, x] = contr.top();
        contr.pop();
        int z = min(x, g);
        x -= z;
        g -= z;
        if (x)
          contr.push({p, x});
        ops.push_back({{p, a[i].se}, z});
      }
    }
  }
  cout << "YES" << endl;
  cout << ops.size() << endl;
  for (auto [x, y] : ops)
    cout << x.fi + 1 << ' ' << x.se + 1 << ' ' << y << endl;
}