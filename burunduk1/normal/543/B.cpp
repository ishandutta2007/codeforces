/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.05.07
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

template <class T = int> inline T readInt(); 

template <const int V, const int E>
struct MultiList {
  int e, he[V], ne[E + 1], to[E + 1];
  void clear( int n = V ) {
    e = 1;
    memset(he, 0, sizeof(he[0]) * n);
  }
  MultiList() : e(1) { }
  void add( int v, int x ) {
    assert(e <= E);
    to[e] = x, ne[e] = he[v], he[v] = e++;
  }
};

const int N = 3000;

MultiList<N, 2 * N> g;
int n, m, cc, u[N];
int s1, t1, l1;
int s2, t2, l2;
int d[N][N];
int qst, qen, q[N];

void bfs( int s, int *d ) {
  cc++;
  qst = qen = 0;
  fill(d, d + n, int(1e8));
  q[qen++] = s, u[s] = cc, d[s] = 0;
  while (qst < qen) { 
    s = q[qst++];
    for (int x, e = g.he[s]; e; e = g.ne[e]) 
      if (u[x = g.to[e]] != cc)
        u[x] = cc, q[qen++] = x, d[x] = d[s] + 1;
  }
}

int main() {
  n = readInt();
  m = readInt();
  forn(_, m) {
    int a = readInt() - 1;
    int b = readInt() - 1;
    g.add(a, b);
    g.add(b, a);
  }
  s1 = readInt() - 1;
  t1 = readInt() - 1;
  l1 = readInt();
  s2 = readInt() - 1;
  t2 = readInt() - 1;
  l2 = readInt();
  forn(i, n) 
    bfs(i, d[i]);

  if (d[s1][t1] > l1 || d[s2][t2] > l2) {
    puts("-1");
    return 0;
  }
  int ans = min(m, d[s1][t1] + d[s2][t2]);
  forn(_, 2) {
    forn(a, n)
      forn(b, n)
        if (d[s1][a] + d[a][b] + d[b][t1] <= l1 && d[s2][a] + d[a][b] + d[b][t2] <= l2) 
          ans = min(ans, d[s1][a] + d[a][b] + d[b][t1] + d[s2][a] + d[b][t2]);
    swap(s2, t2);
  }
  printf("%d\n", m - ans);
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