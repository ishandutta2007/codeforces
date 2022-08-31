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
    vector<ll> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    if (n <= 2) {
      cout << 0 << '\n';
      continue;
    }
    int mx = 0;
    for (ll i = 0; i < n; ++i) {
      for (ll j = 0; j < i; ++j) {
        ll xi = j * (n - 1) * a[i], xj = i * (n - 1) * a[j];
        ll y_num = (xi - xj), y_den = j * (n - 1 - i) - i * (n - 1 - j);
        ll x_num = y_den * (n - 1) * a[i] - (n - 1 - i) * y_num, x_den = i * y_den;
        int cand = 0;
        for (ll k = 0; k < n; ++k) {
          ll lhs = x_num * y_den * k + y_num * x_den * (n - 1 - k);
          ll rhs = a[k] * (n - 1) * x_den * y_den;
          cand += (lhs == rhs);
        }
        mx = max(mx, cand);
      }
    }
    cout << n - mx << '\n';
  }
}