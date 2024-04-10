#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 255;
const int mod = 1e9 + 7;

ll c[N][N];
inline void pre() {
  c[0][0] = 1;
  for (int i = 1; i <= 250; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
}

inline ll C(int n, int m) {
  return c[n][m];
}

inline ll qpow(ll a, ll b) {
  ll res = 1LL;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll n, k;
long long ans = 0LL;

int main() {
  pre();
  read(n, k);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int flag = ((i + j) & 1) ? -1 : 1;
      int u = n * (i + j) - i * j;
      ans += (ll)flag * C(n, i) % mod * C(n, j) % mod * qpow(k - 1, u) % mod * qpow(k, n * n - u) % mod;
      ans %= mod;
    }
  }
  printf("%lld\n", (ans + mod) % mod);
  return 0;
}