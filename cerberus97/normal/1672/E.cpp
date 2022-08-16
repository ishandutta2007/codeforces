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

const int L = 2000, W = 1e9;

int query(int w);

int main() {
  fast_cin();
  int n; cin >> n;
  int lo = 1, hi = n * L + n - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (query(mid) == 1) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  int s = (hi + 1) - (n - 1);
  int ans = (hi + 1);
  for (int i = 0; i < n; ++i) {
    int w = (s + n - 1) / (n - i);
    int q = query(w);
    if (q) {
      ans = min(ans, w * q);
    }
  }
  cout << "! " << ans << endl;
}

int query(int w) {
  if (w < 1 or w > W) {
    return 0;
  }
  cout << "? " << w << endl;
  int ans; cin >> ans;
  return ans;
}