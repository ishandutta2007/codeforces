#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <cassert>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
const int LEN = 100000;

struct fastio {
  int it, len;
  char s[LEN + 5];
  fastio() {
    it = len = 0;
  }
  char get() {
    if (it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get(); c == ' ' || c == '\n' || c == '\r'; c = get());
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if (it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
  }
}buff, bufo;
inline int getint() {
  char c; int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if(c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll() {
  char c; ll res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char() {
  char c;
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get());
  return c;
}

#define maxn 100005
#define mod 1000000007
int n, m, p[maxn], siz[maxn];
vector<int> adj[maxn];
vector<ll> _ws;

void dfs(int u, int f) {
  siz[u] = 1;
  for (auto v : adj[u]) {
    if (v == f) continue;
    dfs(v, u);
    siz[u] += siz[v];
  }
  if (f) _ws.push_back(siz[u] * ll(n - siz[u]));
}

void solve() {
  n = getint();
  for (int i = 1; i <= n; i++) adj[i].clear();
  _ws.clear();
  for (int i = 1; i < n; i++) {
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  m = getint();
  for (int i = 0; i < m; i++) p[i] = getint();
  if (m <= n - 1) {
    sort(p, p + m, greater<int>());
    while (m < n - 1) p[m++] = 1;
  } else {
    sort(p, p + m);
    while (m > n - 1) {
      p[m - 2] = (ll)p[m - 2] * p[m - 1] % mod;
      m--;
    }
    reverse(p, p + m);
  }
  dfs(1, 0);
  sort(_ws.begin(), _ws.end(), greater<ll>());
  ll ans = 0;
  for (int i = 0; i < n - 1; i++) (ans += _ws[i] % mod * p[i]) %= mod;
  putll(ans, '\n');
}

int main() {
  int t = getint();
  while (t--) solve();
  bufo.flush();
  return 0;
}
/*
1
16
5 10
16 1
14 1
7 5
13 2
16 11
1 7
1 4
3 14
8 16
1 6
4 9
4 12
5 13
1 15
18
45893 9901 51229 15511 46559 28433 4231 30241 29837 34421 12953 6577 12143 52711 40493 89 34819 28571
*/