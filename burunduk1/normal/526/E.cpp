/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.04
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

inline int readChar();
template <class T> inline T readInt(); 

const int N = 1e6;

int n, q, a[3 * N], go[2 * N];

inline int cor( int a ) {
  while (a >= n)
    a -= n;
  return a;
}

int main() {
  n = readInt<int>();
  q = readInt<int>();
  forn(i, n)
    a[2 * n + i] = a[n + i] = a[i] = readInt<int>();
  while (q--) {
    ll b = readInt<ll>();
    {
      int r = 0;
      ll sum = 0;
      forn(l, 2 * n) {
        while (r - l < n && sum + a[r] <= b)
          sum += a[r++];
        go[l] = r;
        sum -= a[l];
      }
    }
    int k = n, mi = 0, l = 0, r = 0, len = 0, cnt = 0;
    forn(i, 2 * n) {
      len += go[r] - r, r = cor(go[r]), cnt++;
      //printf("%d --> %d\n", r, go[r]);
      if (go[r] - r < go[mi] - mi)
        mi = r;
      if (len >= n) {
        k = min(k, cnt);
        len -= go[l] - l, l = cor(go[l]), cnt--;
      }
    }
    //printf("n=%d k=%d diff=%d : %d\n", n, k, go[mi] - mi, k * (go[mi] - mi));
    for (int x = mi; x <= go[mi]; x++) {
      cnt = 0;
      //printf("%d, %d :", x, x % n);
      for (int start = cor(x), i = start; i < start + n; i = go[i]) {
        cnt++;
        //printf("[%d]", i);
      }
      //printf(": cnt = %d\n", cnt);
      k = min(k, cnt);
    }          
    printf("%d\n", k);
  }
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