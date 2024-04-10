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

signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

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

const int N = 2000 + 7;
int n, a[N], pre[N];

int get(int l, int r) {
  return pre[r] ^ pre[l - 1];
}

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] ^ a[i];
    }
    bool ok = 0;
    for (int piv = 1; piv < n; piv++) {
      if (get(1, piv) == get(piv + 1, n)) {
        ok = 1;
      }
    }
    for (int last1 = 1; last1 <= n; last1++) {
      for (int last2 = last1 + 1; last2 < n; last2++) {
        if (get(1, last1) == get(last1 + 1, last2) && get(last2 + 1, n) == get(1, last1)) {
          ok = 1;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }

  }
  return 0;
}