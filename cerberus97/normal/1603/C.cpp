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

const int mod = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

int mul(ll a, int b) {
  return (a * b) % mod;
}

struct dp {
  vector<int> dp1, dp2;
  void resize(int sz) {
    dp1.resize(sz, 0);
    dp2.resize(sz, 0);
  }
};

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n), sq(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sq[i] = min(int(sqrt(a[i])) + 2, a[i]);
    }
    dp prv, cur;
    prv.resize(2);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cur.resize(sq[i] + 1);
      int psq = prv.dp1.size() - 1, pa = (i == 0 ? 1 : a[i - 1]);
      for (int j = 1; j <= sq[i]; ++j) {
        // split into j pieces
        int v = a[i] / j;
        if (v <= psq) {
          cur.dp1[j] = add(prv.dp2[v], mul(j - 1, i + 1));
        } else {
          cur.dp1[j] = add(prv.dp1[(pa + v - 1) / v], mul(j - 1, i + 1));
        }
        // split s.t. last piece <= j
        int cnt = (a[i] + j - 1) / j;
        v = a[i] / cnt;
        if (v <= psq) {
          cur.dp2[j] = add(prv.dp2[v], mul(cnt - 1, i + 1));
        } else {
          cur.dp2[j] = add(prv.dp1[(pa + v - 1) / v], mul(cnt - 1, i + 1));
        }
      } 
      ans = add(ans, cur.dp1[1]);
      prv = cur;
    }
    cout << ans << '\n';
  }
}