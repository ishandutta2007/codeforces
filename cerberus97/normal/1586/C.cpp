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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  set<int> bad;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i - 1][j] == 'X' and a[i][j - 1] == 'X') {
        bad.insert(j - 1);
      }
    }
  }
  bad.insert(m + 1);
  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l; --r;
    auto it = bad.lower_bound(l);
    if (*it + 1 <= r) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}