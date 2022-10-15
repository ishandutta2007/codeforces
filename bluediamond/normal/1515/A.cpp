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

const int N = 100 + 7;
int n, x, a[N], s;

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    s = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s += a[i];
    }
    sort(a + 1, a + n + 1);
    if (s == x) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    s = 0;
    for (int i = 1; i <= n; i++) {
      s += a[i];
      if (s == x) {
        assert(i < n);
        swap(a[i], a[n]);
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}