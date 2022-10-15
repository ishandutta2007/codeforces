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

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = r * a % M;
    a = a * a % M;
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return a * pw(b, M - 2) % M;
}

signed realMain() {
  int n, m;
  cin >> n >> m;
  int no_restr = pw(2 * (n + 1), m);
  cout << no_restr * dv(n + 1 - m, n + 1) % M;
  return 0;
}