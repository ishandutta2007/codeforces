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

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

template <class T> inline T sign( T x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template <class T> inline T myAbs( T a ) { return a > 0 ? a : -a; }

#define DEBUG 1
void err( const char *fmt, ... )
{
  #if DEBUG
  va_list list;
  va_start(list, fmt);
  vfprintf(stderr, fmt, list);
  fflush(stderr);
  #endif
}

/* The main part */

const int maxN = (int)1e5 + 10;
const int inf = (int)2e9;

int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};
int p[] = {3, 2, 1, 0};

int res = inf, ri, rki, rj, rkj;
int n, x[maxN], y[maxN], k[maxN], X0[maxN], Y0[maxN];

inline bool pless1( int i, int j ) { return mp(x[i], y[i]) < mp(x[j], y[j]); }
inline bool pless2( int i, int j ) { return mp(y[i], x[i]) < mp(y[j], x[j]); }

int p1[maxN], p2[maxN], D;

inline void Save( int tmp, int i, int j )
{
  res = tmp;
  ri = i, rki = k[i];
  rj = j, rkj = k[j];
}

inline void Try( int i, int j )
{
  int tmp;
  if ((tmp = sqr(x[i] - x[j]) + sqr(y[i] - y[j])) < res)
    Save(tmp, i, j);
}

int mpos = 0, mem[maxN * 5];

void Solve( int n, int *px, int *py )
{
  if (n <= 8)
  {
    forn(ti, n)
      forn(tj, ti)
        Try(px[ti], px[tj]);
    return;
  }

  int n1 = n / 2, n2 = n - n1;
  int *px1 = px, *px2 = px + n1;
  int *py1 = mem + mpos; mpos += n1;
  int *py2 = mem + mpos; mpos += n2;
  int k1 = 0, k2 = 0;

  forn(i, n)
    if (pless1(py[i], px2[0]))
      py1[k1++] = py[i];
    else
      py2[k2++] = py[i];

  Solve(n1, px1, py1);
  Solve(n2, px2, py2);

  forn(i, n)
    for (int j = i + 1; j < n && y[py[j]] - y[py[i]] < D; j++)
      Try(py[i], py[j]);
  mpos -= n;
}
 
void Solve()
{
  D = inf;
  forn(i, n)
    p1[i] = p2[i] = i;
  sort(p1, p1 + n, pless1);
  sort(p2, p2 + n, pless2);
  forn(i, n - 1)
    if (x[p1[i]] == x[p1[i + 1]] && y[p1[i]] == y[p1[i + 1]])
    {
      Save(0, p1[i], p1[i + 1]);
      return;
    }
  Solve(n, p1, p2);
}

int main()
{
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));

  srand((int)1e9 + 9);
  scanf("%d", &n);
  forn(i, n)
    scanf("%d%d", &X0[i], &Y0[i]);
  forn(i, n)
  {
    k[i] = -1;
    do
    {
      k[i]++;
      x[i] = X0[i] * dx[k[i]];
      y[i] = Y0[i] * dy[k[i]];
    } while (!(x[i] >= 0 && y[i] >= 0));
  }
  Solve();
  err("ans = %d\n", res);
  printf("%d %d %d %d\n", ri + 1, rki + 1, rj + 1, p[rkj] + 1);
  return 0;
}