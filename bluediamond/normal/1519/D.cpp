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

const int N = 5000 + 7;
int n, a[N], b[N], pre[N], cost[N][N], kek[N];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i] * b[i];
  }
  int best = 0;
  for (int sum = 2; sum <= 2 * n; sum++) {
    int first = max(1LL, sum - n);
    for (int i = 1; i <= n; i++) {
      int j = sum - i;
      if (j < 1 || j > n) {
        continue;
      }
      int last = min(i, j);
      if (first <= last) {
        kek[first] += a[j] * b[i];
        kek[last + 1] -= a[j] * b[i];
      }
    }
    int cur = 0;
    for (int l = 1; l <= n; l++) {
      cur += kek[l];
      kek[l] = 0;
      if (cur != 0) {
        cost[l][sum - l] += cur;
      }
    }
  }
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      best = max(best, cost[l][r] - pre[r] + pre[l - 1]);
    }
  }
  cout << best + pre[n] << "\n";
  return 0;
}