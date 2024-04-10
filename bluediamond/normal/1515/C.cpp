#include <bits/stdc++.h>
///#pragma GCC target("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")


/**
#pragma GCC opimize("O3")
#pragma GCC opimization ("unroll-loops")

**/
using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}


signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x;
    set<pair<int, int>> sums;
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
      sums.insert({0, i});
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cin >> x;
      auto it = *sums.begin();
      sums.erase(it);
      cout << it.second << " ";
      it.first += x;
      sums.insert(it);
    }
    cout << "\n";


  }
  return 0;
}