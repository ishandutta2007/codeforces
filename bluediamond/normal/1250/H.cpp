#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 2000;
ll n, x[N], y[N], c[N], k[N], d[N][N], init[N], par[N];
bool act[N];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (ll i = 0; i < n; i++) {
    act[i] = 1;
    cin >> x[i] >> y[i];
  }

  for (ll i = 0; i < n; i++) {
    cin >> c[i];
    init[i] = c[i];
  }

  for (ll i = 0; i < n; i++) {
    cin >> k[i];
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      d[i][j] = (ll) (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
    }
  }

  ll ans = 0;
  vector<ll> a;
  vector<pair<ll, ll>> b;

  set<pair<ll, ll>> st;
  for (ll i = 0; i < n; i++) {
    st.insert({c[i], i});
  }

  for (ll it = 0; it < n; it++) {
    ll cmin = (ll) 1e18;
    ll id;

    for (ll i = 0; i < n; i++) {
      if (act[i] && c[i] < cmin) {
        cmin = c[i];
        id = i;
      }
    }

    ans += cmin;
    act[id] = 0;
    if (c[id] == init[id]) {
      a.push_back(id);
    } else {
      b.push_back({id, par[id]});
    }

    for (ll i = 0; i < n; i++) {
      if (act[i]) {
        c[i] = min(c[i], d[id][i]);
        if (d[id][i] == c[i]) {
          par[i] = id;
        }
      }
    }
  }

  cout << ans << "\n";
  cout << (ll) a.size() << "\n";

  for (auto &x : a) {
    cout << x + 1 << " ";
  }
  cout << "\n";

  cout << (ll) b.size() << "\n";
  for (auto &x : b) {
    cout << x.first + 1 << " " << x.second + 1 << "\n";
  }

  return 0;
}