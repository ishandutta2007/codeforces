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
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
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

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

inline int sign( int x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
inline int myAbs( int a ) { return a > 0 ? a : -a; }

const int maxn = 1010;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char s[maxn][maxn];
int h, w, n, a[maxn][maxn];
vector <pii> v[maxn * maxn];

int main()
{
  scanf("%d%d", &h, &w);
  forn(i, h)
    scanf("%s", s[i]);
  forn(i, h)
    forn(j, w)
      if (s[i][j] == '.' && s[i][j + 1] == '.')
      {        
        a[i][j] = a[i][j + 1] = ++n;
        s[i][j] = s[i][j + 1] = '#';
      }
  forn(j, w)
    forn(i, h)
      if (s[i][j] == '.' && s[i + 1][j] == '.')
      {
        a[i][j] = a[i + 1][j] = ++n;
        s[i][j] = s[i + 1][j] = '#';
      }
  //fprintf(stderr, "1\n");
  forn(i, h)
    forn(j, w)
      if (s[i][j] == '.')
      {
        forn(k, 4)
        {
          int i1 = i + dy[k], j1 = j + dx[k];
          if (0 <= i1 && i1 < h && 0 <= j1 && j1 < w && a[i1][j1])
            a[i][j] = a[i1][j1], s[i][j] = '#';
        }
        if (!a[i][j])
        {
          puts("-1");
          return 0;
        }
      }
  ///fprintf(stderr, "2\n");
/*
  forn(i, h)
  {
    forn(j, w)
      printf("%d%c ", a[i][j], s[i][j]);
    puts("");
  }
*/
  forn(i, h)
    forn(j, w)
      if (a[i][j])
        v[a[i][j]].pb(mp(j, i));
  memset(a, -1, sizeof(a));
  forab(i, 1, n)
  {
    assert(sz(v[i]) > 0);
    int is[11];
    memset(is, 0, sizeof(is));
    forn(j, sz(v[i]))
      forn(k, 4)
      {
        int x = v[i][j].first + dx[k];
        int y = v[i][j].second + dy[k];
        if (0 <= x && x < w && 0 <= y && y < h && a[y][x] != -1)
          is[a[y][x]] = 1;
      }

    int val = 0;
    while (is[val])
      val++;
    assert(val < 10);
    forn(j, sz(v[i]))
      a[v[i][j].second][v[i][j].first] = val;
  }
  //fprintf(stderr, "3\n");
  forn(i, h)
  {
    forn(j, w)
      if (a[i][j] == -1)
        putchar('#');
      else
        putchar('0' + a[i][j]);
    puts("");
  }
  return 0;         
}