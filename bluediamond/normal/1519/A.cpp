#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
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
    int r, b, d;
    cin >> r >> b >> d;
    int kek = r * (d + 1);
    if (b > kek) {
      cout << "NO\n";
      continue;
    }
    swap(r, b);
    kek = r * (d + 1);
    if (b > kek) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}