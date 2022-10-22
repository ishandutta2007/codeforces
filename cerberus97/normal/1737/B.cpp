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
const ll MX = 1e9 + 42;

ll bsearch(ll l, ll r, int diff);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (int i = 0; i < 3; ++i) {
      ans += bsearch(l, r, i);
    }
    cout << ans << '\n';
  }
}

ll bsearch(ll l, ll r, int diff) {
  ll lo = 1, hi = MX;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    if (mid * (mid + diff) >= l) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  ll x = hi + 1;
  lo = 1; hi = MX;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    if (mid * (mid + diff) <= r) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  ll y = lo - 1;
  return (y - x + 1);
}