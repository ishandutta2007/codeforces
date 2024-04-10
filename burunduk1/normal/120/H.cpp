/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

/* Template */

#include <cstdarg>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>
#include <queue>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define fill(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)
#define LAST(a) a[sz(a) - 1]

typedef unsigned int uint;
typedef double dbl;
typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef unsigned char byte;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

#define DEBUG 0
void err( const char *fmt, ... )
{
  #if DEBUG
  va_list list;
  va_start(list, fmt);
  vfprintf(stderr, fmt, list);
  #endif
}

const int maxN = 200;
const int maxV = (int)1e6;
const int maxHash = 27 * 27 *27 * 27;

int n, vn = 0, no[maxHash];
vi c[maxN];
int pa[maxV], u[maxN], pa2[maxN];
string str[maxV];

/* The main part */

int getNo( char *s )
{
  int hash = 0;
  for (int i = 0; s[i]; i++)
    hash = hash * 26 + (s[i] - 'a' + 1);
  if (!no[hash])
  {
    str[vn] = string(s);
    no[hash] = ++vn;
  }
  return no[hash] - 1;
}

char s[103], res[103];

void go( vi &v, int i, int k )
{
  if (!s[i])
  {
    res[k] = 0;
    if (k)
      v.pb(getNo(res));
    return;
  }
  go(v, i + 1, k);
  if (k < 4)
    res[k] = s[i], go(v, i + 1, k + 1);
}

int dfs( int v )
{
  u[v] = 1;
  forn(i, sz(c[v]))
  {
    int x = c[v][i];
    if (pa[x] == -1 || (!u[pa[x]] && dfs(pa[x])))
    {
      pa[x] = v, pa2[v] = x;
      return 1;
    }
  }
  return 0;
}

int main()
{
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));

  scanf("%d", &n);
  forn(i, n)
  {
    scanf("%s", s);
    go(c[i], 0, 0);
  }

  err("ok\n");

  fill(pa, -1);
  forn(i, n)
  {
    err("%d: ", i);
    forn(j, sz(c[i]))
      err("%d=%s ", c[i][j], str[c[i][j]].c_str());
    err("\n");
  }
  forn(i, n)
  {
    fill(u, 0);
    if (!dfs(i))
    {
      puts("-1");
      return 0;
    }

  }
  forn(i, n)
    printf("%s\n", str[pa2[i]].c_str());
  return 0;
}