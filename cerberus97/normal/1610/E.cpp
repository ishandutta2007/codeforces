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
    for (auto& i : a) {
      cin >> i;
    }
    map<ll, int> mp;
    for (auto& i : a) {
      ++mp[i];
    }
    int ans = 0;
    for (auto& [k, v] : mp) {
      int cand = v;
      ll dist = 1;
      while (true) {
        auto it = mp.lower_bound(k + dist);
        if (it == mp.end()) {
          break;
        }
        ++cand;
        dist = 2 * (it->first - k);
      }
      ans = max(ans, cand);
    }
    cout << n - ans << '\n';
  }
}