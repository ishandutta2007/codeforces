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

bool isq(int x) {
  int r = sqrt(x);
  return (r * r == x);
}


signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    bool ok = 0;
    cin >> n;
    if (n % 2 == 0 && isq(n / 2)) {
      ok = 1;
    }
    if (n % 4 == 0 && isq(n / 4)) {
      ok = 1;
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}