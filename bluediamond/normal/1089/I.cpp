#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 400 + 7;
int q, mod, fact[N], no_pre[N], ways[N][N], ret[N];

int add(int a, int b) {
  a += b;
  if (a >= mod) return a - mod;
  if (a < 0) return a + mod;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
}


signed realMain() {
  cin >> q >> mod;
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  for (int i = 1; i < N; i++) {
    no_pre[i] = fact[i];
    for (int j = 1; j < i; j++) {
      no_pre[i] = add(no_pre[i], -mul(fact[j], no_pre[i - j]));
    }
  }
  ways[0][0] = 1;
  for (int n = 1; n < N; n++) {
    for (int k = 1; k < N; k++) {
      for (int last = 1; last <= n; last++) {
        ways[n][k] = add(ways[n][k], mul(fact[last], ways[n - last][k - 1]));
      }
    }
  }
  for (int i = 1; i < N; i++) {
    ret[i] = fact[i];
    for (int j = 1; j < i; j++) {
      ret[i] = add(ret[i], -mul(2, mul(fact[j], no_pre[i - j])));
    }
    for (int k = 3; k < i; k++) {
      ret[i] = add(ret[i], -mul(ways[i][k], ret[k]));
    }
  }
  ret[2] = 2;
  while (q--) {
    int n;
    cin >> n;
    cout << ret[n] << "\n";
  }
  return 0;
}