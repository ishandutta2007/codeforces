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
    vector<int> a(n);
    map<vector<int>, int> mp;
    for (auto& val : a) {
      cin >> val;
      int sq = sqrt(val);
      vector<int> primes;
      for (int p = 2; p <= sq; ++p) {
        bool par = 0;
        while (val % p == 0) {
          val /= p;
          par ^= 1;
        }
        if (par) {
          primes.pb(p);
        }
      }
      if (val > 1) {
        primes.pb(val);
      }
      ++mp[primes];
    }
    int sum = 0, mx = 0;
    for (auto& [k, v] : mp) {
      mx = max(mx, v);
      if (v % 2 == 0 or k.empty()) {
        sum += v;
      }
    }
    int q; cin >> q;
    while (q--) {
      ll w; cin >> w;
      if (w == 0) {
        cout << mx << '\n';
      } else {
        cout << max(mx, sum) << '\n';
      }
    }
  }
}