#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

const int MAXN = 200010;

bool z[MAXN];
int ans;
set<int> x[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    x[a].insert(b);
    x[b].insert(a);
    ans -= z[a];
    ans -= z[b];
    z[a] = *x[a].rbegin() > a;
    z[b] = *x[b].rbegin() > b;
    ans += z[a];
    ans += z[b];
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      x[a].insert(b);
      x[b].insert(a);
      ans -= z[a];
      ans -= z[b];
      z[a] = *x[a].rbegin() > a;
      z[b] = *x[b].rbegin() > b;
      ans += z[a];
      ans += z[b];
    } else
    if (t == 2) {
      int a, b;
      cin >> a >> b;
      x[a].erase(b);
      x[b].erase(a);
      ans -= z[a];
      ans -= z[b];
      if (x[a].size() > 0) {
        z[a] = *x[a].rbegin() > a;
      } else {
        z[a] = false;
      }
      if (x[b].size() > 0) {
        z[b] = *x[b].rbegin() > b;
      } else {
        z[b] = false;
      }
      ans += z[a];
      ans += z[b];
    } else {
      cout << n - ans << "\n";
    }
  }

  return 0;
}