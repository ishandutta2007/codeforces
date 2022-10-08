/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.04
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

inline int readChar();
template <class T = int> inline T readInt(); 

typedef long long ll;

struct TreeMax {
  int *t, n;
  TreeMax( int n, int *a ) : n(n) {
    t = new int[2 * n];
    copy(a, a + n, t + n);
    for (int i = n - 1; i > 0; i--)
      t[i] = max(t[2 * i], t[2 * i + 1]);
  }
  void change( int i, int x ) {
    t[n + i] = x;
    for (i = (n + i) / 2; i > 0; i /= 2)
      t[i] = max(t[2 * i], t[2 * i + 1]);
  }
  int get( int l, int r ) {
    int res = INT_MIN;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if ((l & 1) == 1) res = max(res, t[l++]);
      if ((r & 1) == 0) res = max(res, t[r--]);
    }
    return res;
  }
};

struct TreeMin {
  int *t, n;
  TreeMin( int n, int *a ) : n(n) {
    t = new int[2 * n];
    copy(a, a + n, t + n);
    for (int i = n - 1; i > 0; i--)
      t[i] = min(t[2 * i], t[2 * i + 1]);
  }
  void change( int i, int x ) {
    t[n + i] = x;
    for (i = (n + i) / 2; i > 0; i /= 2)
      t[i] = min(t[2 * i], t[2 * i + 1]);
  }
  int get( int l, int r ) {
    int res = INT_MAX;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if ((l & 1) == 1) res = min(res, t[l++]);
      if ((r & 1) == 0) res = min(res, t[r--]);
    }
    return res;
  }
};

const int N = 3e5;
const int K = 19;

int jump[N][K];

int main() {
  int n = readInt();
  int x[n], y[n];
  forn(i, n) {
    int X = readInt() - 1;
    int Y = readInt() - 1;
    x[Y] = X;
    y[X] = Y;
  }
  int next[n + 1], ly[n], ry[n];
  TreeMax t_maxx(n, x);
  TreeMin t_minx(n, x);
  TreeMax t_maxy(n, y);
  TreeMin t_miny(n, y);
  for (int i = n - 2; i >= 0; i--) {
    int t = i + 1;
    int minY = min(y[i], y[i + 1]);
    int maxY = max(y[i], y[i + 1]);
    while (t_maxx.get(minY, maxY) > t) {
      minY = min(minY, ly[t]);
      maxY = max(maxY, ry[t]);
      t = next[t];
    }
    next[i] = t;
    ly[i] = minY;
    ry[i] = maxY;
    //printf("%d : next = %d, y = [%d..%d]\n", i, next[i], ly[i], ry[i]);
  }
  set<int> ys;
  ys.insert(-1);
  ys.insert(n);

  next[n - 1] = next[n] = n;
  forn(i, n + 1)
    jump[i][0] = next[i];
  forn(k, K - 1)
    forn(i, n + 1)
      jump[i][k + 1] = jump[jump[i][k]][k];

  ll ans = 1;
  forn(i, n - 1) {
    auto it = ys.lower_bound(y[i]);
    int maxY = *it;
    int minY = *--it;
    ys.insert(y[i]);

    int t = i;
    for (int k = K - 1; k >= 0; k--) {
      int tmp = jump[t][k];
      if (tmp < n && t_maxy.get(i, tmp) <= maxY && minY <= t_miny.get(i, tmp))
        ans += 1 << k, t = tmp;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}

/** Read */

static const int buf_size = 4096;

inline int getchar_fast() { // you may use getchar() instead of it
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getchar_fast();
  while (c <= 32)
    c = getchar_fast();
  return c;
}                

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getchar_fast();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar_fast();
  return s == 1 ? x : -x;
}