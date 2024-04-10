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

const int maxn = (int)1e5;

int n, a, b, x[maxn], p[maxn], ans[maxn];

inline int xless1( int i, int j ) { return mp(x[i], i) < mp(x[j], j); }
inline int xless2( int i, int j ) { return mp(x[i], -i) < mp(x[j], -j); }

int main()
{
  scanf("%d%d%d", &n, &a, &b);
  forn(i, n)
    scanf("%d", &x[i]), p[i] = i;
  if (a == b)
  {
    forn(t, 2)
      forn(i, a)
        printf("%d ", t + 1);
    return 0;
  }

  int va = 1, vb = 2, t = 0;
  if (a > b)
    sort(p, p + n, xless1);
  else 
  {
    sort(p, p + n, xless2);
    swap(a, b), swap(va, vb);
  }
  forn(i, a)
    ans[p[t++]] = va;
  forn(i, b)
    ans[p[t++]] = vb;
  forn(i, n)
    printf("%d%c", ans[i], EOL(i, n));
  return 0;
}