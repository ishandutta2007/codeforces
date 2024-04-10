#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 10, oo = 1e18;
void solve() {
   ll n, m;
   cin >> n >> m;
   vector<ll> p(n);
   for (int i = 0; i < n; ++i) {
      cin >> p[i];
   }
   p.push_back(-oo);
   p.push_back(oo);
   sort(p.begin(), p.end());
   n = (int)p.size();
   vector<pair<int, int>> x;
   for (int i = 0; i < m; ++i) {
      int l, r; cin >> l >> r;
      int id = lower_bound(p.begin(), p.end(), l) - p.begin();
      if (p[id] <= r) {
         continue;
      }
      x.emplace_back(l, r);
   }
   sort(x.begin(), x.end(), [&](pair<int, int> u, pair<int, int> v) {
      if (u.first == v.first) {
         return u.second > v.second;
      }
      return u.first < v.first;
   });
   vector<pair<int, int>> useful;
   stack<int> s;
   for (int i = 0; i < (int)x.size(); ++i) {
      auto [l, r] = x[i];
      while (!s.empty()) {
         auto [L, R] = x[s.top()];
         if (R < r) {
            break;
         }
         s.pop();
      }
      s.push(i);
   }
   while (!s.empty()) {
      useful.push_back(x[s.top()]);
      s.pop();
   }
   sort(useful.begin(), useful.end());
   m = (int)useful.size();
   vector<array<ll, 2>> dp(n, {oo, oo});
   dp[0][0] = dp[0][1] = 0;
   auto mini = [&](ll & x, ll y) {
      if (x > y) {
         x = y;
      }
   };
   for (int i = 0, l = 0, r = 0; i + 1 < n; ++i) {
      while (l < m && useful[l].first < p[i]) ++l;
      while (r < m && useful[r].first < p[i + 1]) ++r;
      for (int cut = l; cut <= r; ++cut) {
         ll lft = (cut > l ? useful[cut - 1].first - p[i] : 0);
         ll rgh = (cut < r ? p[i + 1] - useful[cut].second : 0);
         ll opt0 = dp[i][0] + lft;
         ll opt1 = dp[i][1] + 2LL * lft;
         mini(dp[i + 1][0], min(opt0, opt1) + 2LL * rgh);
         mini(dp[i + 1][1], min(opt0, opt1) + rgh);
      }
   }
   cout << min(dp.back()[0], dp.back()[1]) << '\n';
}
int main() {
   ios::sync_with_stdio(0); cin.tie(0);
   int T = 1; cin >> T;
   while (T--) {
      solve();
   }
}