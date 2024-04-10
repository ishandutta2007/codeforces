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

#define maxn 262149
int n, q, a[maxn], R;
ll sum[maxn << 1];

void up(int id) {
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
}

void build(int id, int l, int r) {
  if (l == r) sum[id] = a[l];
  else {
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
  }
}

void update(int id, int l, int r, int pos, int x) {
  if (l == r) {
    sum[id] = x;
  } else {
    int hei = __builtin_popcount(r - l);
    int dir = (pos >> (hei - 1) & 1) ^ (R >> (hei - 1) & 1);
    int mid = (l + r) >> 1;
    if (dir) update(id << 1 | 1, mid + 1, r, pos, x);
    else update(id << 1, l, mid, pos, x);
    up(id);
  }
}

ll qsum(int id, int l, int r, int pos) {
  if (l == r) return sum[id];
  int hei = __builtin_popcount(r - l);
  int dir = (pos >> (hei - 1) & 1) ^ (R >> (hei - 1) & 1);
  int mid = (l + r) >> 1;
  ll ans = 0;
  if (pos >> (hei - 1) & 1) ans += sum[id << 1 | !dir];
  if (dir) ans += qsum(id << 1 | 1, mid + 1, r, pos);
  else ans += qsum(id << 1, l, mid, pos);
  return ans;
}
  
int main() {
  n = getint(), q = getint();
  n = 1 << n;
  for (int i = 0; i < n; i++) a[i] = getint();
  build(1, 0, n - 1);
  while (q--) {
    int fl = getint();
    if (fl == 1) {
      int x = getint() - 1, k = getint();
      update(1, 0, n - 1, x, k);
    } else if (fl == 2) {
      int k = getint();
      R ^= (1 << k) - 1;
    } else if (fl == 3) {
      int k = getint();
      R ^= 1 << k;
    } else {
      int l = getint() - 1, r = getint() - 1;
      ll ans = qsum(1, 0, n - 1, r);
      if (l) ans -= qsum(1, 0, n - 1, l - 1);
      putll(ans, '\n');
    }
  }
  bufo.flush();
  return 0;
}