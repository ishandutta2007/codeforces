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

pll solve(vector<vector<int>>& g, vector<ll>& s, int u, int k);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; ll k;
    cin >> n >> k;
    vector<int> p(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
      cin >> p[i];
      g[p[i]].pb(i);
    }
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
    }
    cout << solve(g, s, 1, k).first << '\n';
  }
}

pll solve(vector<vector<int>>& g, vector<ll>& s, int u, int k) {
  ll ans1 = k * s[u], ans2 = ans1 + s[u];
  int cnt = g[u].size();
  if (cnt == 0) {
    return {ans1, ans2};
  }
  int base = (k / cnt);
  vector<ll> child_scores;
  for (auto& v : g[u]) {
    auto tmp = solve(g, s, v, base);
    child_scores.pb(tmp.second - tmp.first);
    ans1 += tmp.first;
    ans2 += tmp.first;
  }
  sort(child_scores.begin(), child_scores.end(), greater<ll>());
  int rem1 = (k % cnt), rem2 = rem1 + 1;
  for (auto& score : child_scores) {
    if (rem1 > 0) ans1 += score;
    if (rem2 > 0) ans2 += score;
    --rem1; --rem2;
  }
  return {ans1, ans2};
}