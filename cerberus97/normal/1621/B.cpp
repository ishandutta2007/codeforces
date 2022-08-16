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
const ll inf = 1e18 + 42;

struct ivl {
  ll l, r, c;
};

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ivl> a(n);
    for (auto& iv : a) {
      cin >> iv.l >> iv.r >> iv.c;
    }
    ll min_l = inf, max_r = -inf, longest = 0;
    ll lcost = inf, rcost = inf, lgcost = inf;
    for (auto& iv : a) {
      if (tie(iv.l, iv.c) < tie(min_l, lcost)) {
        min_l = iv.l;
        lcost = iv.c;
      }
      if (tie(max_r, iv.c) < tie(iv.r, rcost)) {
        max_r = iv.r;
        rcost = iv.c;
      }
      ll tmp = iv.r - iv.l + 1;
      if (tie(longest, iv.c) < tie(tmp, lgcost)) {
        longest = iv.r - iv.l + 1;
        lgcost = iv.c;
      }
      ll ans = lcost + rcost;
      if (longest == max_r - min_l + 1) {
        ans = min(ans, lgcost);
      }
      cout << ans << '\n';
    }
  }
}