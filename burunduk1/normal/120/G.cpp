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
  #endif
}

/* The main part */

const int maxN = 103;

int m, n, t, a[maxN][2], b[maxN][2], c[maxN];
vector <string> res[maxN];
char name[maxN][99];
int q[maxN], qst, qen, d[maxN][maxN];

int main()
{
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));

  scanf("%d%d", &n, &t);
  forn(i, n)
    forn(j, 2)
      scanf("%d%d", &a[i][j], &b[i][j]);
  scanf("%d", &m);
  forn(i, m)
    scanf("%s%d", name[i], &c[i]), q[qen++] = i;
  

  int I = 0, J = 0;
  while (qst != qen)
  {
    int T = t;
    while (T > 0 && qst != qen)
    {
      int K = q[qst++]; qst %= maxN;
      int need = max(1, c[K] - (a[I][J] + b[I][J ^ 1]) - d[I][K]);
      if (need <= T)
        T -= need, res[I].pb(name[K]);
      else
      {
        d[I][K] += T, T = 0;
        q[qen++] = K; qen %= maxN;
      }
    }

    if (++I == n)
      I = 0, J = (J + 1) % 2;
  }
  
  forn(i, n)
  {
    printf("%d", sz(res[i]));
    forn(j, sz(res[i]))
      printf(" %s", res[i][j].c_str());
    puts("");
  }
  return 0;
}