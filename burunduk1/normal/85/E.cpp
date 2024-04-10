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

const int MOD = (int)1e9 + 7;
const int maxn = 5010;
const int maxd = 10010;

int n, x[maxn], y[maxn];
vi v[maxd];
int p[maxn], si[maxn], col[maxn];

int get( int i )
{
  if (i == p[i])
    return i;
  int v = get(p[i]);
  if (v != p[i])
  {
    assert(p[p[i]] == v);
    col[i] ^= col[p[i]], p[i] = v;
  }
  return v;
}

int color( int i )
{
  if (i == p[i])
    return col[i];
  return col[i] ^ color(p[i]);
}

void join( int i, int j, int is )
{
  assert(i != j);
  if (si[i] > si[j])
    swap(i, j);
  si[j] += si[i], p[i] = j;
  assert(col[i] == 0 && col[j] == 0);
  col[i] = is;
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d%d", &x[i], &y[i]);
  if (n == 2)
  {
    printf("0\n2\n");
    return 0;
  }
  forn(i, n)
    forn(j, i)
      v[myAbs(x[i] - x[j]) + myAbs(y[i] - y[j])].pb((i << 15) + j);

  int num = n, res = -1, resd = -1;
  forn(i, maxn)
    p[i] = i, si[i] = 1, col[i] = 0;
  fornd(d, maxd)
  {
    res = num;
    int bad = 0;
    forn(t, sz(v[d]))
    {
      int i = v[d][t] >> 15;
      int j = v[d][t] & ((1 << 15) - 1);
      if (get(i) == get(j))
      {
        if (color(i) == color(j))
          bad = 1;
      }
      else
      {
        num--;
        join(get(i), get(j), color(i) == color(j));
      }
    }
    if (bad)
    {
      resd = d;
      break;
    }
  }

  int ans = 1;
  forn(i, res)
    ans = (ans * 2) % MOD;
  printf("%d\n%d\n", resd, ans);
  return 0;
}