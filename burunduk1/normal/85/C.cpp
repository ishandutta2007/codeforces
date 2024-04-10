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

const int maxn = (int)1e5 + 10;

int root, n, l[maxn], r[maxn], x[maxn], p[maxn], dep[maxn], Left[maxn], Right[maxn];
vector <pii> end;
int last, lca[maxn];
double val[maxn];

void calc( int v, int k )
{
  assert(v != -1);
  dep[v] = k;
  if (l[v] == -1)
  {
    end.pb(mp(x[v], v));
    last = v;
    Left[v] = Right[v] = x[v];
    return;
  }
  calc(l[v], k + 1);
  lca[last] = v;
  calc(r[v], k + 1);
  Left[v] = Left[l[v]];
  Right[v] = Right[r[v]];
}

void calc2( int v )
{
  if (l[v] == -1)
    return;
  val[l[v]] += val[v] + Left[r[v]];
  val[r[v]] += val[v] + Right[l[v]];
  calc2(l[v]);
  calc2(r[v]);
}

int main()
{
  scanf("%d", &n);
  memset(l, -1, sizeof(l));
  memset(r, -1, sizeof(r));
  forn(i, n)
  {
    scanf("%d%d", &p[i], &x[i]), p[i]--;
    if (p[i] == -2)
      root = i;
    else
      if (l[p[i]] == -1)
        l[p[i]] = i;
      else
        r[p[i]] = i;
  }
  forn(v, n)
    if (l[v] != -1 && x[l[v]] > x[r[v]])
      swap(l[v], r[v]);

  calc(root, 0);
  calc2(root);

  //forn(v, n)
  //  printf("%d: x=%d, right=%d, left=%d, val=%d\n", v, x[v], Right[v], Left[v], val[v]);

  int m;
  scanf("%d", &m);
  while (m--)
  {
    int y, v;
    scanf("%d", &y);
    if (y < end[0].first)
      v = end[0].second;
    else if (y > end[sz(end) - 1].first)
      v = end[sz(end) - 1].second;
    else
    {
      int j = lower_bound(all(end), mp(y, 0)) - end.begin();

      assert(j > 0 && j < sz(end));
      int v1 = end[j - 1].second;
      int v2 = end[j].second;
      int Lca = lca[v1];
      if (y < x[Lca])
        v = v1;
      else
        v = v2;
    }
    //fprintf(stderr, "v=%d, x=%d, dep=%d, val=%d\n", v, x[v], dep[v], val[v]);
    printf("%.20lf\n", val[v] / (dep[v]));
  }
  return 0;
}