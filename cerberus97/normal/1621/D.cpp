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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<vector<int>> a(2 * n, vector<int>(2 * n));
    for (auto& r : a) {
      for (auto& c : r) {
        cin >> c;
      }
    }
    ll ans = 0;
    for (int i = n; i < 2 * n; ++i) {
      for (int j = n; j < 2 * n; ++j) {
        ans += a[i][j];
      }
    }
    int cand = inf;
    for (int i = 0; i < n; i += max(1, n - 1)) {
      for (int j = n; j < 2 * n; j += max(1, n - 1)) {
        cand = min(cand, a[i][j]);
        cand = min(cand, a[j][i]);
      }
    }
    cout << ans + cand << '\n';
  }
}