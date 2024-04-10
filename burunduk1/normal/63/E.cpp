/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

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

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

int sign( int x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }

char s[50][50], is[50][50];
int st, cc, no[50][50];
vi c[1 << 19];
int f[1 << 19];

int go( int v )
{
  if (f[v] != -1)
    return f[v];
  f[v] = 0;
  forn(i, sz(c[v]))
    f[v] |= (go(c[v][i]) == 0);
  return f[v];
}

int main()
{
  forn(i, 5)
    gets(s[i]);
  forn(i, 5)
    forn(j, 10)
      if ((is[i][j] = (s[i][j] == 'O' || s[i][j] == '.')) != 0)
        st |= (s[i][j] == 'O') << cc, no[i][j] = cc++;

  assert(cc == 19);
  forn(pr, 1 << 19)
    if ((pr & st) == pr)
    {
      int dx[] = {2, 1, -1};
      int dy[] = {0, 1, 1};

      forn(y, 5)
        forn(x, 10)
          if (is[y][x] && IS(pr, no[y][x]))
            forn(k, 3)
            {
              int x1 = x, y1 = y, pr1 = pr;
              do
              {
                assert(IS(pr1, no[y1][x1]));
                pr1 ^= 1 << no[y1][x1];
                c[pr].pb(pr1);
                x1 += dx[k], y1 += dy[k];
              } while (0 <= y1 && y1 < 5 && 0 <= x1 && x1 < 10 && is[y1][x1] && IS(pr, no[y1][x1]));
            }
    }
  memset(f, -1, sizeof(f));
  puts(go(st) ? "Karlsson" : "Lillebror");
  return 0;
}