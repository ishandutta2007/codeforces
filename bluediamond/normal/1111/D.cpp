#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

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

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

int code(char ch) {
  if ('a' <= ch && ch <= 'z') {
    return ch - 'a';
  } else {
    return ch - 'A' + 26;
  }
}

const int N = (int) 1e5 + 7;
const int K = 52;
int fact[N], ifact[N];
int n, q, ret[K][K], all, f[K], ways[N], sol[N];
string init;

signed realMain() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  cin >> init >> q;
  n = (int) init.size();
  for (int i = 0; i < n; i++) {
    f[code(init[i])]++;
  }
  all = mul(fact[n / 2], fact[n / 2]);
  for (int i = 0; i < K; i++) {
    all = dv(all, fact[f[i]]);
  }
  {
    vector<int> sticks;
    for (int k = 0; k < K; k++) {
      if (f[k] == 0) {
        continue;
      }
      sticks.push_back(f[k]);
    }
    sort(sticks.begin(), sticks.end());
    for (int x = 0; x <= n; x++) {
      ways[x] = 0;
    }
    ways[0] = 1;
    int sum = 0;
    for (auto &len : sticks) {
      sum = min(sum, n - len);
      for (int i = sum; i >= 0; i--) {
        ways[i + len] = add(ways[i + len], ways[i]);
      }
      sum += len;
    }
    for (int x = 0; x <= n; x++) {
      sol[x] = ways[x];
    }
  }
  for (int i = 0; i < K; i++) {
    for (int j = i + 1; j < K; j++) {
      if (f[i] == 0 || f[j] == 0) {
        continue;
      }
      for (int x = 0; x <= n; x++) {
        ways[x] = sol[x];
      }
      for (int x = f[i]; x <= n; x++) {
        ways[x] = add(ways[x], -ways[x - f[i]]);
      }
      for (int x = f[j]; x <= n; x++) {
        ways[x] = add(ways[x], -ways[x - f[j]]);
      }
      if (f[i] + f[j] <= n / 2) {
        ret[i][j] = add(ways[n / 2], ways[n / 2 - f[i] - f[j]]);
      }
    }
  }
  for (int it = 1; it <= q; it++) {
    int i, j;
    cin >> i >> j;
    i = code(init[i - 1]);
    j = code(init[j - 1]);
    if (i > j) {
      swap(i, j);
    }
    if (i == j) {
      cout << mul(sol[n / 2], all) << "\n";
    } else {
      cout << mul(ret[i][j], all) << "\n";
    }
  }
  return 0;
}