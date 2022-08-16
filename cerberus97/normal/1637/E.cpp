/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    set<pii> banned;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      banned.insert({x, y});
      banned.insert({y, x});
    }
    map<int, int> cnt;
    for (auto& i : a) {
      ++cnt[i];
    }
    vector<vector<int>> by_cnt(n + 1);
    vector<int> cnts;
    for (auto& [k, v] : cnt) {
      by_cnt[v].pb(k);
      cnts.pb(v);
    }
    sort(cnts.begin(), cnts.end());
    cnts.erase(unique(cnts.begin(), cnts.end()), cnts.end());
    int sz = cnts.size();
    ll ans = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j <= i; ++j) {
        int c1 = cnts[i], c2 = cnts[j];
        int s1 = by_cnt[c1].size(), s2 = by_cnt[c2].size();
        ll cand = 0;
        for (int p1 = s1 - 1; p1 >= 0; --p1) {
          bool ok = true;
          for (int p2 = (i == j ? p1 - 1 : s2 - 1); p2 >= 0; --p2) {
            if (banned.count({by_cnt[c1][p1], by_cnt[c2][p2]})) {
              ok = false;
              continue;
            } else {
              cand = max(cand, ll(by_cnt[c1][p1] + by_cnt[c2][p2]));
              break;
            }
          }
          if (ok) {
            break;
          }
        }
        ans = max(ans, cand * (c1 + c2));
      }
    }
    cout << ans << '\n';
  }
}