#include<bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y) {
  if(x < y) swap(x, y);
  if(y == 0) return x;
  return __gcd(x, y);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
  while(ntest--) {
    int n, m; cin >> n >> m;
    vector<long long> a(n);;
    for(long long &x : a) cin >> x;

    vector<pair<vector<int>, int>> g(n);
    for(int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      --u; --v;
      g[v].first.emplace_back(u);
    }

    for(int i = 0; i < n; ++i) g[i].second = i, sort(g[i].first.begin(), g[i].first.end());
    sort(g.begin(), g.end());

    long long cur = 0, ans = 0;
    for(int i = 0; i < n; ++i) {
      if(g[i].first.empty()) continue;

      if(i > 0 && g[i].first != g[i - 1].first) {
        ans = gcd(ans, cur);
        cur = a[g[i].second];
      }
      else {
        cur += a[g[i].second];
      }
    }

    ans = gcd(ans, cur);
    cout << ans << "\n";
  }

  return 0;
}