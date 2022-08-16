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

const int N = 2e6 + 10;

int main() {
  fast_cin();
  int n; cin >> n;
  vector<ll> a(n);
  vector<bool> have(N, false);
  for (auto& i : a) {
    cin >> i;
    have[i] = true;
  }
  vector<int> le(N), ge(N);
  le[0] = -1;
  for (int i = 1; i < N; ++i) {
    le[i] = (have[i] ? i : le[i - 1]);
  }
  ge[N - 1] = -1;
  for (int i = N - 2; i >= 0; --i) {
    ge[i] = (have[i] ? i : ge[i + 1]);
  }
  auto first_in = [&](ll l, ll r) {
    if (l > a[n - 1] or r < a[0]) {
      return -1;
    }
    l = max(l, a[0]);
    return (ge[l] <= r ? ge[l] : -1);
  };
  auto last_in = [&](ll l, ll r) {
    if (l > a[n - 1] or r < a[0]) {
      return -1;
    }
    r = min(r, a[n - 1]);
    return (le[r] >= l ? le[r] : -1);
  };
  for (ll x = 1; ; ++x) {
    ll lo = x * x - a[0];
    ll hi = ((x * x) + (x + 1) * (x + 1)) / 2 - a[0] + 1;
    if (hi <= 0) {
      continue;
    }
    lo = max(lo, 0ll);
    ll lo_bak = lo;
    for (ll y = x; ; ++y) {
      if (a[n - 1] + lo_bak < y * y) {
        break;
      }
      ll lo2 = y * y;
      ll mid2 = ((y * y) + (y + 1) * (y + 1)) / 2;
      ll hi2 = (y + 1) * (y + 1);
      ll z = last_in(lo2 - lo_bak, mid2 - lo_bak);
      if (z != -1) {
        hi = min(hi, mid2 - z + 1);
      }
      z = first_in(mid2 + 1 - lo_bak, hi2 - 1 - lo_bak);
      if (z != -1) {
        lo = max(lo, hi2 - z);
      }
    }
    if (lo < hi) {
      cout << lo << endl;
      break;
    }
  }  
}