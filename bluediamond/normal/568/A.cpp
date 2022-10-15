#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
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

int inv(int x) {
  int ret = 0;
  while (x) {
    ret = 10 * ret + x % 10;
    x /= 10;
  }
  return ret;
}

const int N = (int) 2e6 + 7;
bool prim[N];
int pi[N], pl[N];

signed realMain() {
  prim[2] = 1;
  for (int i = 3; i < N; i += 2) {
    prim[i] = 1;
  }
  for (int i = 3; i * i < N; i += 2) {
    if (prim[i]) {
      for (int j = i * i; j < N; j += 2 * i) {
        prim[j] = 0;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    pi[i] = pi[i - 1] + prim[i];
    pl[i] = pl[i - 1] + (inv(i) == i);
  }
  int p, q, ret = -1;
  cin >> p >> q;
  for (int n = 1; n < N; n++) {
    if ((ll) pi[n] * q <= (ll) p * pl[n]) {
      ret = n;
    }
  }
  cout << ret << "\n";
  return 0;
}