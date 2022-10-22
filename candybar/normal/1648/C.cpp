/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

const ll mod = 998244353;
#define maxn 200005
int s[maxn], t[maxn], n, m;
ll cnt[maxn], fct[maxn];

ll modpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % mod;
    y >>= 1;
    (x *= x) %= mod;
  }
  return res;
}
ll inv(ll x) { return modpow(x, mod - 2); }

ll bit[maxn];
void add(int pos, int x) {
  for (int i = pos; i <= 200000; i += i & -i)
    bit[i] += x;
}
ll qsum(int pos) {
  ll res = 0;
  for (int i = pos; i; i -= i & -i)
    res += bit[i];
  return res;
}

void solve() {
  fct[0] = 1;
  for (int i = 1; i <= 200000; i++)
    fct[i] = fct[i - 1] * i % mod;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", s + i);
    cnt[s[i]]++, cnt[0]++;
    add(s[i], 1);
  }
  for (int i = 1; i <= m; i++)
    scanf("%d", t + i);
  ll ans = 0, foo = fct[cnt[0]];
  for (int i = 1; i <= 200000; i++)
    (foo *= inv(fct[cnt[i]])) %= mod;
  for (int i = 1; i <= m; i++) {
    if (!cnt[0])
      (ans += 1) %= mod;
    else
      (ans += qsum(t[i] - 1) * inv(cnt[0]) % mod * foo) %= mod;
    if (!cnt[t[i]])
      break;
    (foo *= inv(cnt[0]) * cnt[t[i]] % mod) %= mod;
    cnt[t[i]]--, cnt[0]--;
    add(t[i], -1);
  }
  printf("%lld\n", (ans + mod) % mod);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  solve();
  return 0;
}