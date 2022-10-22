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

#define maxn 100005
#define mp make_pair
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;

int n, a[10], b[maxn], k;
P fret[maxn * 6];
int cnt[maxn];

int main() {
  for (int i = 1; i <= 6; i++) a[i] = getint();
  n = getint();
  for (int i = 1; i <= n; i++) b[i] = getint();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      fret[(i - 1) * 6 + j] = mp(b[i] - a[j], i);
    }
  }
  sort(fret + 1, fret + 6 * n + 1);
  int ans = inf;
  for (int i = 1, j = 0, tot = 0; i <= 6 * n; i++) {
    for (; j < 6 * n && tot < n; j++) {
      tot += !cnt[fret[j + 1].second];
      cnt[fret[j + 1].second]++;
    }
    if (tot < n) break;
    chmin(ans, fret[j].first - fret[i].first);
    cnt[fret[i].second]--;
    tot -= !cnt[fret[i].second];
  }
  putint(ans, '\n');
  bufo.flush(); 
  return 0;
}