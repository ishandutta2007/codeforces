/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

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

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }

inline void relax( ll &a, ll b )
{
  a = max(a, b);
}

const ll inf = (ll)1e18;
const int maxn = 1510;

int h, w;
int a[maxn][maxn];
ll b[maxn][maxn];
ll f[maxn][maxn];

int main()
{
  scanf("%d%d", &h, &w);
  forn(i, h)
    forn(j, w)
      scanf("%d", &a[i][j]);
  forn(i, h)
    forn(j, w)
      b[i][j + 1] = b[i][j] + a[i][j];

  forn(i, h)
    forn(j, w)
      f[i][j] = -inf;
  f[0][0] = a[0][0];

  ll res = -inf;
  forn(i, h)
  {
    if (i % 2 == 0)
      forn(j, w)
      {
        if (i % 2 == 0 && j > 0)
          relax(f[i + 1][j - 1], f[i][j] + b[i + 1][j]);
        if (i % 2 == 1 && j + 1 < w)
          relax(f[i + 1][j + 1], f[i][j] + b[i + 1][j + 2]);
        if (i % 2 == 0 && j + 1 < w)
          relax(f[i][j + 1], f[i][j] + a[i][j + 1]);
        if (i % 2 == 1 && j > 0)
          relax(f[i][j - 1], f[i][j] - a[i][j]);
        if (i == h - 1)
          relax(res, f[i][j]);
      }
    else
      fornd(j, w)
      {
        if (i % 2 == 0 && j > 0)
          relax(f[i + 1][j - 1], f[i][j] + b[i + 1][j]);
        if (i % 2 == 1 && j + 1 < w)
          relax(f[i + 1][j + 1], f[i][j] + b[i + 1][j + 2]);
        if (i % 2 == 0 && j + 1 < w)
          relax(f[i][j + 1], f[i][j] + a[i][j + 1]);
        if (i % 2 == 1 && j > 0)
          relax(f[i][j - 1], f[i][j] - a[i][j]);
        if (i == h - 1)
          relax(res, f[i][j]);
      }
  }
  cout << res << endl;
  return 0;
}