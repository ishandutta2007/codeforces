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

const int N = 1e5 + 10, mod = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

int mul(ll a, int b) {
  return (a * b) % mod;
}

int pwr(int x, int e) {
  int res = 1;
  while (e) {
    if (e & 1) {
      res = mul(res, x);
    }
    e /= 2;
    x = mul(x, x);
  }
  return res;
}

int main() {
  fast_cin();
  int n; cin >> n;
  int dt = 0, a = 0, b = 0, c = 0, t1 = 0, t2 = 0;
  bool any = false;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    if (s == "??") {
      ++c;
    } else if (s == "WW") {
      ++dt;
      any = true;
    } else if (s == "BB") {
      --dt;
      any = true;
    } else if (s == "?W" or s == "W?") {
      ++b;
      if (s == "?W") {
        ++t1;
      } else {
        ++t2;
      }
    } else if (s == "?B" or s == "B?") {
      ++a;
      if (s == "B?") {
        ++t1;
      } else {
        ++t2;
      }
    } else if (s == "BW") {
      ++t1;
    } else {
      ++t2;
    }
  }
  vector<int> fact(2 * n + 1, 1), finv(2 * n + 1, 1);
  for (int i = 2; i <= 2 * n; ++i) {
    fact[i] = mul(fact[i - 1], i);
    finv[i] = pwr(fact[i], mod - 2);
  }
  auto choose = [&](int x, int y) {
    return mul(mul(fact[x], finv[y]), finv[x - y]);
  };
  int ans = 0;
  for (int d1 = -c; d1 <= c; ++d1) {
    int req = -(dt + d1);
    if (req < -a or req > b) {
      continue;
    }
    int ways = mul(choose(2 * c, c + d1), choose(a + b, b - req));
    // cout << d1 << ' ' << ways << endl;
    ans = add(ans, ways);
  }
  if (!any) {
    int tot = pwr(2, c);
    int good = (!t1 + !t2);
    ans = sub(ans, sub(tot, good));
  }
  cout << ans << '\n';
}