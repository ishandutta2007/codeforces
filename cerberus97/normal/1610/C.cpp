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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    int lo = 1, hi = n;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      int nxt = 1;
      for (int i = 0; i < n; ++i) {
        if (b[i] >= nxt - 1 and a[i] >= mid - nxt) {
          ++nxt;
        }
      }
      if (nxt > mid) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    cout << lo - 1 << '\n';
  }
}