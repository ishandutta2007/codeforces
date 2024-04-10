/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }
inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }
/** End fast allocation */

typedef pair <int, int> pii;

const int N = 2e5;

int n, m, cc, u[N], pa[N], have[N], value[N];
vector<int> c[N];
vector<pii> v[N];

bool dfs( int v ) {
  u[v] = cc;
  for (int x : c[v])
    if (pa[x] == -1 || (u[pa[x]] != cc && dfs(pa[x]))) {
      pa[x] = v;
      return 1;
    }
  return 0;
}

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void flush();

int main() {
  n = readInt();
  m = readInt();
  forn(i, n) {
    int k = readInt();
    while (k--) {
      int x = readInt();
      v[abs(x) - 1].pb(mp(i, x > 0));
    }
  }
  forn(i, m) {
    if (sz(v[i]) == 1 || (sz(v[i]) == 2 && v[i][0].second == v[i][1].second)) {
      value[i] = v[i][0].second;
      for (auto p : v[i])
        have[p.first] = 1;
    }
    for (auto p : v[i])
      c[p.first].pb(i);
  }
  fill(pa, -1);
  int o[n];
  forn(i, n)
    o[i] = i;
  random_shuffle(o, o + n);
  forn(_i, n) {
    int i = o[_i];
    if (!have[i]) {
      cc++;
      if (!dfs(i)) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  forn(i, m) {
    if (pa[i] != -1) {
      int j = 0;
      while (v[i][j].first != pa[i])
        j++;
      value[i] = v[i][j].second;
    }
    putchar('0' + value[i]);
  }
}

/** Read */

static const int buf_size = 4096;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32)
    c = getChar();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}