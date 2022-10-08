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

inline ll sqr(ll x) { return x * x; }

const int maxA = (int)1e6 + 10;
const int maxN = (int)2e5 + 10;
const int maxT = 1 << 18;

int sum[maxA];
int n, k, a[maxN], l[maxN], r[maxN], p[maxN], u[maxN];
ll S, ans[maxN];

int prev[maxN], f[maxN];
int val[maxT * 2];
int ind[maxT * 2];

bool inline pless1( int i, int j )
{
  if (r[i] != r[j]) return r[i] < r[j];
  if (l[i] != l[j]) return l[i] < l[j];
  return i < j;
}

bool inline pless2( int i, int j )
{
  if (r[i] != r[j]) return r[i] < r[j];
  if (l[i] != l[j]) return l[i] > l[j];
  return i < j;
}

inline int is( int a, int l, int r ) { return l <= a && a <= r; }

int cnt1 = 0;

inline void add( int i, int x )
{
  cnt1++;
  S += (2 * x * sum[a[i]] + 1) * (ll)a[i];
  sum[a[i]] += x;
}

void Change( int l1, int r1, int l2, int r2 )
{
  while (l1 <= r1 && !is(l1, l2, r2)) add(l1++, -1);
  while (l1 <= r1 && !is(r1, l2, r2)) add(r1--, -1);
  while (l2 <= r2 && !is(l2, l1, r1)) add(l2++, +1);
  while (l2 <= r2 && !is(r2, l1, r1)) add(r2--, +1);
}

int Diff( int i, int j  )
{
  int l1 = l[i], r1 = r[i], l2 = l[j], r2 = r[j];
  return r1 - l1 + 1 + r2 - l2 + 1 - max(0, min(r1, r2) - max(l1, l2) + 1);
}

int rInd;
int rVal;

void Get( int l, int r )
{
  l += maxT, r += maxT;
  rVal = -1;
  while (l <= r)
  {
    if (l % 2 == 1)
    {
      if (val[l] > rVal)
        rVal = val[l], rInd = ind[l];
      l++;
    }
    if (r % 2 == 0)
    {
      if (val[r] > rVal)
        rVal = val[r], rInd = ind[r];
      r--;
    }
    if (l > r)
      break;
    l >>= 1, r >>= 1;
  }
}

void Set( int i, int f, int fi )
{
  i += maxT;
  if (val[i] >= f)
    return;
  val[i] = f, ind[i] = fi;
  for (i >>= 1; i > 0; i >>= 1)
  {
    int t = (val[2 * i] > val[2 * i + 1] ? 2 * i : 2 * i + 1);
    val[i] = val[t], ind[i] = ind[t];
  }
}

int prev1[maxN], prev2[maxN];
vi next[maxN];
int on, o[maxN];

void dfs( int v )
{
  u[v] = 1;
  forn(i, sz(next[v]))
    if (!u[next[v][i]])
      dfs(next[v][i]);
  o[on++] = v;
}

int cnt = 0;

void Do( int i, int &L, int &R )
{
//  if (++cnt % 1000 == 0)
//    fprintf(stderr, "cnt=%d cnt1=%d\n", cnt, cnt1);
  Change(L, R, l[i], r[i]), L = l[i], R = r[i];
  ans[i] = S;
  u[i] = 1;
  forn(j, sz(next[i]))
  {
    int v = next[i][j];
    if (!u[v])
      Do(v, L, R);
  }
}

int main()
{
  scanf("%d%d", &n, &k);
  forn(i, n)
    scanf("%d", &a[i]);
  forn(i, k)
  {
    scanf("%d%d", &l[i], &r[i]), p[i] = i, u[i] = 0;
    l[i]--, r[i]--;
  }

  {
    sort(p, p + k, pless1);
    memset(val, -1, sizeof(val));
    int i, res = -1, ri = -1;
    forn(j, k)
      if (!u[i = p[j]])
      {
        prev1[i] = -1, f[i] = 1;
        Get(0, l[i]);
        if (rVal >= f[i])
          f[i] = rVal + 1, prev1[i] = rInd;
        Set(l[i], f[i], i);
        if (f[i] > res)
          res = f[i], ri = i;
      }
  }
  {
    sort(p, p + k, pless2);
    memset(val, -1, sizeof(val));
    int i, res = -1, ri = -1;
    forn(j, k)
      if (!u[i = p[j]])
      {
        prev2[i] = -1, f[i] = 1;
        Get(l[i], r[i]);
        if (rVal >= f[i])
          f[i] = rVal + 1, prev2[i] = rInd;
        Set(l[i], f[i], i);
        if (f[i] > res)
          res = f[i], ri = i;
      }
  }

  forn(i, k)
    if (prev1[i] == -1 || prev2[i] == -1)
      prev[i] = max(prev1[i], prev2[i]);
    else if (Diff(prev1[i], i) < Diff(prev2[i], i))
      prev[i] = prev1[i];
    else
      prev[i] = prev2[i];
  forn(i, k)
    if (prev[i] != -1)
    {
      //fprintf(stderr, "%d --> %d (k=%d)\n", i, prev[i], k);
      next[prev[i]].pb(i);
    }
  on = 0;
  forn(i, k)
    if (!u[i])
      dfs(i);
  assert(on == k);
  memset(u, 0, sizeof(u));
  
  //fprintf(stderr, "Do!\n");

  fornd(j, k)
  {
    int i = o[j];
    if (!u[i])
    {
      memset(sum, 0, sizeof(sum));
      S = 0;
      int L = 0, R = -1;
      Do(i, L, R);
    }
  }

  forn(i, k)
    printf("%I64d\n", ans[i]);
  return 0;
}