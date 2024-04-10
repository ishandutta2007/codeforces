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
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

const int MAXN = 110;
const int INF = 1000000009;

multiset<LL> x[MAXN];
LL ans[MAXN][MAXN];



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      x[i].clear();
      for (int j = 0; j < m; ++j) {
        LL a;
        cin >> a;
        x[i].insert(a);
      }
    }
    for (int j = 0; j < m; ++j) {
      LL mind = INF, t = -1;
      for (int i = 0; i < n; ++i) {
        if (*x[i].begin() < mind) {
          mind = *x[i].begin();
          t = i;
        }
      }
      ans[t][j] = mind;
      x[t].erase(x[t].find(mind));
      for (int i = 0; i < n; ++i) {
        if (i == t) continue;
        auto iter = x[i].end();
        --iter;
        ans[i][j] = *iter;
        x[i].erase(iter);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << ans[i][j] << " ";
      cout << '\n';
    }
  }
  return 0;
}