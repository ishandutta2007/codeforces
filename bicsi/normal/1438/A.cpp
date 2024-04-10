#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(x...)
#endif 

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int m; cin >> m;
    vector<int> ans(m, 1);
    debug(ans);
    for (auto x : ans) cout << x << " "; cout << endl;
  }
  return 0;
}