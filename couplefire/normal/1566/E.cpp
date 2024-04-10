#include <bits/stdc++.h>
#define ar array

using namespace std;
using ll = long long;

const int mxN = 2e5;
vector<int> g[mxN];
int ans;
bool solve(int cur, int prv) {
  
  int removable = 0, nonremovable = 0;

  bool is_leaf = true;
  for (int nxt : g[cur]) {
    if (nxt == prv) continue;
    is_leaf = false;
    bool res = solve(nxt, cur);
    removable += res;
    nonremovable += !res;
  }

  if (is_leaf)
    return false;

  ans += max(nonremovable-1, 0);

  return nonremovable;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T; cin >> T; while (T--) {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
      g[i].clear();
    for (int nn = 0; nn < n-1; ++nn) {
      int i, j; cin >> i >> j; --i, --j;
      g[i].push_back(j);
      g[j].push_back(i);
    }

    ans = 0;
    solve(0, 0);
    cout << ans+1 << '\n';
  }
}