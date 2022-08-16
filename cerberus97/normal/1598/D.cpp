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
    int n; cin >> n;
    vector<pii> pts(n);
    for (auto& [x, y] : pts) {
      cin >> x >> y;
    }
    map<int, ll> mpx, mpy;
    for (auto& [x, y] : pts) {
      ++mpx[x];
      ++mpy[y];
    }
    ll ans = (ll(n) * ll(n - 1) * (n - 2)) / 6;
    for (auto& [x, y] : pts) {
      ans -= (mpx[x] - 1) * (mpy[y] - 1);
    }
    cout << ans << '\n';
  }
}