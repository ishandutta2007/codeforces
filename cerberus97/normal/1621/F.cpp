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

ll solve(vector<int> groups, int cur, ll a, ll b, ll c);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n, a, b, c;
    string s;
    cin >> n >> a >> b >> c >> s;
    vector<int> groups = {0};
    char cur = '0';
    for (auto& i : s) {
      if (cur != i) {
        groups.pb(0);
        cur = i;
      }
      ++groups.back();
    }
    ll ans = max(solve(groups, 0, a, b, c), solve(groups, 1, a, b, c));
    cout << ans << '\n';
  }
}

ll solve(vector<int> groups, int cur, ll a, ll b, ll c) {
  ll ans = 0;
  vector<ll> good;
  ll zero = 0, one = 0, pay = 0, fpay = 0;
  int n = groups.size();
  for (int i = 0; i < n; i += 2) {
    if (i != 0 and i != n - 1) {
      good.pb(groups[i] - 1);
    } else {
      if (groups[i]) {
        zero += groups[i] - 1;
        ++fpay;
      }
    }
  }
  for (int i = 1; i < n; i += 2) {
    one += groups[i] - 1;
  }
  sort(good.begin(), good.end(), greater<ll>());
  while (!good.empty() and good.back() == 0) {
    good.pop_back();
    ++pay;
  }
  while (true) {
    if (cur == 0) {
      if (!one and pay and b >= c) {
        ans -= c;
        --pay;
        ++one;
      } else if (!good.empty()) {
        ans += a;
        --good.back();
        if (good.back() == 0) {
          good.pop_back();
          ++pay;
        }
      } else if (zero) {
        ans += a;
        --zero;
      } else if (one and pay and b >= c) {
        ans -= c;
        --pay;
        ++one;
      } else if (one and fpay and b >= c) {
        ans -= c;
        --fpay;
      } else {
        break;
      }
    } else {
      if (!one) {
        break;
      } else {
        --one;
        ans += b;
      }
    }
    cur ^= 1;
  }
  return ans;
}