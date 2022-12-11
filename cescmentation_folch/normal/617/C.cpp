#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll dist(pll a, pll b) {
  return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

int main() {
  ll n;
  pll p1, p2;
  cin >> n;
  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  ll res = 1e18;
  pll P[n];
  for (int i = 0; i < n; ++i) cin >> P[i].first >> P[i].second;
  for (int i = 0; i < n; ++i) {
    ll dd = dist(p1, P[i]);
    ll tt = 0;
    for (int j = 0; j < n; ++j) {
      if (dd < dist(p1, P[j])) tt = max(tt, dist(p2, P[j]));
    }
    res = min(res, tt + dd);
  }
  ll tt = 0;
  for (int j = 0; j < n; ++j) {
      tt = max(tt, dist(p2, P[j]));
    }
  cout << min(res, tt) << endl;
}