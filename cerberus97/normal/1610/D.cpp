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

const int LOG = 30, mod = 1e9 + 7;

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

int mul(ll a, int b) {
  return (a * b) % mod;
}

int main() {
  fast_cin();
  int n; cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  vector<int> p2(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    p2[i] = mul(2, p2[i - 1]);
  }
  int ans = p2[n];
  for (int p = 1; p < LOG; ++p) {
    vector<int> cnt(2, 0);
    for (auto& i : a) {
      if (i % (1 << p) == 0) {
        ++cnt[(i >> p) & 1];
      }
    }
    if (cnt[1]) {
      ans = sub(ans, p2[cnt[0] + cnt[1] - 1]);
    }
  }
  cout << sub(ans, 1) << '\n';
}