#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
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
template<class T> bool chmin(T &x, T y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, T y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
int n, x[maxn];
char s[maxn];

vector<int> chi[maxn];
int w[maxn], V, par[maxn];

void dfs(int u) {
  if (u) printf("%d ", w[u]);
  for (auto v : chi[u]) {
    dfs(v);
  }
}

void solve() {
  int u = 0;
  w[0] = n + 1;
  for (int i = 1; i <= (n << 1); i++) {
    if (s[i] == '+') {
      chi[u].push_back(++V);
      par[V] = u;
      u = V;
    } else {
      if (!u) {
        puts("NO");
        return;
      }
      w[u] = x[i];
      u = par[u];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (w[par[i]] < w[i]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
  dfs(0);
  puts("");
}

int main() {
  n = getint();
  for (int i = 1; i <= (n << 1); i++) {
    s[i] = get_char();
    if (s[i] == '-') x[i] = getint();
  }
  solve();
  return 0;
}