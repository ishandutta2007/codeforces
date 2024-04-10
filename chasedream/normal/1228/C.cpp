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

const ll mod = 1e9 + 7;
vector <int> fac;
void Sieve(ll x) {
  int sq = sqrt(x);
  for (int i = 2; i <= sq; i++) {
    if (x % i == 0) {
      fac.push_back(i);
      while (x % i == 0)
        x /= i;
    }
  }
  if (x > 1) fac.push_back(x);
}

ll qpow(ll a, ll b) {
  ll res = 1LL;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod; b >>= 1;
  }
  return res;
}

ll f(ll n, ll v) {
  ll res = 1LL;
  while (n > 0) {
    (res *= qpow(v, n / v)) %= mod;
    n /= v;
  }
  return res;
}

ll x, n;

int main() {
  read(x, n);
  Sieve(x);
  long long ans = 1LL;
  for (auto v: fac) {
    (ans *= f(n, v)) %= mod;
  }
  printf("%lld\n", ans);
  return 0;
}