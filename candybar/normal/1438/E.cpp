/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <climits>
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
    if (it == LEN) fwrite(s, 1, LEN, stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
    it = 0;
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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
int n;
ll sum[maxn], a[maxn];

ll qsum(int l, int r) {
  return sum[r] - sum[l - 1];
}
bool check(int l, int r) {
  return l + 2 <= r && (a[l] ^ a[r]) == qsum(l + 1, r - 1);
}

ll solve(int l, int r) {
  if (l + 1 >= r) return 0;
  int mid = (l + r) >> 1;
  vector<int> ls, rs; 
  for (int i = mid; i >= l; i--) {
    if (qsum(i + 1, mid) <= a[i]) ls.push_back(i);
  }
  for (int i = mid + 1; i <= r; i++) {
    if (qsum(mid + 1, i - 1) <= a[i]) rs.push_back(i);
  }
  ll ans = solve(l, mid) + solve(mid + 1, r);
  for (auto i : ls) {
    for (int j = mid + 1; j <= r; j++)
      ans += check(i, j);
  }
  for (auto j : rs) {
    for (int i = l; i <= mid; i++)
      ans += check(i, j);
  }
  for (auto i : ls) {
    for (auto j : rs) {
      ans -= check(i, j);
    }
  }
  return ans;
}

int main() {
  n = getint();
  for (int i = 1; i <= n; i++) {
    a[i] = getint();
    sum[i] = sum[i - 1] + a[i];
  }
  putll(solve(1, n), '\n');
  bufo.flush();
  return 0;
}