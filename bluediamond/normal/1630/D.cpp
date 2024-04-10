#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;

bool home = 1;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //// exit(0);

#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }
  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int n, _, g = 0;
    cin >> n >> _;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
      x *= -1;
    }
    for (int i = 1; i <= _; i++) {
      int x;
      cin >> x;
      g = __gcd(g, x);
    }

    vector<vector<ll>> best(g, vector<ll>(2, -INF));
    for (int r = 0; r < g; r++) {
      vector<int> guys;
      ll ttl = 0;
      for (int i = r; i < n; i += g) {
        guys.push_back(a[i]);
        ttl += a[i];
      }
      sort(guys.begin(), guys.end());
      best[r][0] = max(best[r][0], ttl);
      for (int j = 0; j < (int)guys.size(); j++) {
        ttl -= 2 * guys[j];
        best[r][(j + 1) % 2] = max(best[r][(j + 1) % 2], ttl);
      }
    }
    int limit = n % g;
    if (limit == 0) {
      limit = -1;
    }

    vector<ll> sol(2, 0);
    for (int i = 0; i < g; i++) {
      sol[i < limit] += best[i][0];
      sol[i >= limit] += best[i][1];
    }
    cout << max(sol[0], sol[1]) << "\n";

  }
}