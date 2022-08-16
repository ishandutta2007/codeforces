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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template<typename has_less>
using ordered_set =
tree<has_less,
  null_type,
  less<has_less>,
  rb_tree_tag,
  tree_order_statistics_node_update>;

const int N = 1e5 + 10, A = 26;
const ll inf = 1e18 + 42;

int main() {
  fast_cin();
  int tc; cin >> tc;
  while (tc--) {
    int n; string s, t;
    cin >> n >> s >> t;
    vector<vector<int>> at(A);
    for (int i = n - 1; i >= 0; --i) {
      at[s[i] - 'a'].pb(i);
    }
    ll ans = inf, cur = 0;
    ordered_set<int> used;
    for (int i = 0; i < n; ++i) {
      int p = n, here = t[i] - 'a';
      for (int c = 0; c < here; ++c) {
        if (!at[c].empty()) {
          p = min(p, at[c].back());
        }
      }
      if (p < n) {
        ans = min(ans, cur + p - ll(used.order_of_key(p)));
      }
      // match till i
      if (at[here].empty()) {
        break;
      }
      p = at[here].back();
      at[here].pop_back();
      cur += p - used.order_of_key(p);
      used.insert(p);
    }
    if (ans == inf) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}