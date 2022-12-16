#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll n, m, x;
    cin >> n >> m>> x;
    vector<ll> a(n+1), z(n+1), y(m+1);
    set<pair<ll, ll>> s;
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
      if (i <= m) {
        y[i] = a[i];
        s.insert({a[i], i});
        z[i] = i;
      }
    }
    for (int i=m+1; i<=n; ++i) {
      auto [yj, j] = *s.begin();
      s.erase({yj, j});
      z[i] = j;
      y[j] += a[i];
      s.insert({y[j], j});
    }
    cout << "YES\n";
    for (int i=1; i<=n; ++i) {
      cout << z[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}