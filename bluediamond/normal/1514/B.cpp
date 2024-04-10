#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
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

const int M = (int) 1e9 + 7;

int rep(int x) {
  x %= M;
  if (x < 0) {
    x += M;
  }
  return x;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = rep(r * a);
    a = rep(a * a);
    b /= 2;
  }
  return r;
}

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << pw(n, k) << "\n";
  }
  return 0;
}