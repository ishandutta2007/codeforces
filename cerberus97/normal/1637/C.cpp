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
    bool ok = false;
    ll sum = 0;
    int cnt_odd = 0;
    for (int i = 1; i < n - 1; ++i) {
      sum += a[i];
      if (a[i] > 1) {
        ok = true;
      }
      if (a[i] % 2 == 1) {
        ++cnt_odd;
      }
    }
    if (n == 3 and a[1] % 2 == 1) {
      ok = false;
    }
    if (ok) {
      cout << (sum + cnt_odd) / 2 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}