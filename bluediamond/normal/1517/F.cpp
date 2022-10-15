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
///#define int ll

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

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 300 + 7;
int n, r;
vector<int> g[N];
int tot[N][N];
int nu[N][N];
int dep[N];
int newtot[N];
int newnu[N];

void addup(int &a, int x) {
  a = add(a, x);
}

void build(int a, int p = -1) {
  dep[a] = 1;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
      build(b, a);
      dep[a] = max(dep[a], 1 + dep[b]);
    }
  }
  g[a] = kids;
}

void dfs(int a) {
  if (g[a].empty()) {
    tot[a][0] = 1;
    nu[a][0] = 1;
    return;
  }
  tot[a][0] = 1;
  nu[a][0] = 1;
  int cur = 0;
  for (auto &b : g[a]) {
    dfs(b);
    for (int i = 1; i <= dep[b]; i++) {
      if (tot[b][i - 1]) {
        int x = tot[b][i - 1];
        for (int j = 0; j <= cur; j++) {
          if (tot[a][j]) {
            int y = tot[a][j], coef = mul(x, y);
            addup(newtot[min(i, j)], coef);
          }

          if (nu[a][j]) {
            int y = nu[a][j], coef = mul(x, y);
            if (i + j <= r) {
              addup(newtot[i], coef);
            } else {
              addup(newnu[j], coef);
            }
          }
        }
      }
      if (nu[b][i - 1]) {
        int x = nu[b][i - 1];
        for (int j = 0; j <= cur; j++) {
          if (tot[a][j]) {
            int y = tot[a][j], coef = mul(x, y);
            if (i + j <= r) {
              addup(newtot[j], coef);
            } else {
              addup(newnu[i], coef);
            }
          }

          if (nu[a][j]) {
            int y = nu[a][j], coef = mul(x, y);
            addup(newnu[max(i, j)], coef);
          }
        }
      }
    }
    cur = max(cur, dep[b] + 1);
    for (int i = 0; i <= cur; i++) {
      tot[a][i] = newtot[i];
      nu[a][i] = newnu[i];
      if (i > r) {
        nu[a][i] = 0;
      }
      newtot[i] = newnu[i] = 0;
    }
  }
}

int cnt[N];

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  build(1);
  for (int raz = 0; raz <= n + 1; raz++) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        tot[i][j] = nu[i][j] = 0;
      }
    }
    r = raz;
    dfs(1);
    int sol = 0;
    for (int i = 0; i <= n; i++) {
      sol = add(sol, tot[1][i]);
    }
    cnt[raz] = sol;
  }
  cnt[n + 1] = add(cnt[n + 1], 1);
  assert(cnt[n + 1] == pw(2, n));
  int ret = 0;
  for (int i = 0; i <= n + 1; i++) {
    int kek = (i - 1 + M) % M;
    ret = add(ret, mul(kek, add(cnt[i], -cnt[i - 1])));
  }
  ret = dv(ret, pw(2, n));
  cout << ret << "\n";
  return 0;
}