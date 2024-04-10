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

int n, next[maxn], t[maxn], u[maxn], fail[maxn];
vi c[maxn];
int A, B;

struct Result
{
  int num, good;

  Result() { num = good = 0; }
  Result( int a, int b ) : num(a), good(b) { }

  Result operator + ( Result a ) { return Result(num + a.num, good + a.good); }
  Result operator - ( Result a ) { return Result(num - a.num, good - a.good); }
  Result add( int v1, int v2 ) { return Result(num + (v1 != v2), good + (t[v1] != t[v2])); }

  pii F() { return mp(num, good); }
};

Result Max( Result a, Result b ) { return a.F() > b.F() ? a : b; }

typedef pair <Result, Result> pRR;

int Pair[maxn];

pRR calc( int v )
{
  u[v] = 2;

  Result f0;
  Result add;
  int pv = -1;

  forn(i, sz(c[v]))
  {
    int x = c[v][i];
    if (x == v) continue;
    if (v == A && x == B)
      continue;
    pRR tmp = calc(x);
    f0 = f0 + tmp.second;

    Result add1 = (tmp.first - tmp.second).add(x, v);
    if (add1.F() > add.F() && !fail[v] && !fail[x])
      pv = x, add = add1;
  }
  Pair[v] = pv;
  Result f1 = f0 + add;
//  printf("F(%d) = [%d,%d] and [%d,%d], pair = %d\n", v, f0.num, f0.good, f1.num, f1.good, Pair[v]);
  return mp(f0, f1);
}

vi p1, p2;

void AddPair( int v, int x )
{
  if (v != x)
    p1.pb(v), p2.pb(x);
}

void Out1( int v );

void Out0( int v )
{
  forn(i, sz(c[v]))
  {
    int x = c[v][i];
    if (x == v) continue;
    if (v == A && x == B)
      continue;
    Out1(x);
  }
}

void Out1( int v )
{
  int pv = Pair[v];
//  printf("Out1(%d, pair=%d)\n", v, pv);
  forn(i, sz(c[v]))
  {
    int x = c[v][i];
    if (x == v) continue;
    if (v == A && x == B)
      continue;
    if (x != pv)
      Out1(x);
    else
    {
      AddPair(v, x);
      Out0(x);
    }
  }
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
  {
    scanf("%d%d", &next[i], &t[i]), next[i]--;
    c[next[i]].pb(i);
  }

  Result res;
  forn(i, n)
    if (!u[i])
    {  
      int j = i;
      while (!u[j])
        u[j] = 1, j = next[j];

      A = next[j], B = j;
      //printf("j=%d, next=%d\n", j, next[j]);
      //puts("calc1:");
      Result tmp1 = calc(j).second;
      fail[j] = fail[next[j]] = 1;
      //puts("calc2:");
      Result tmp2 = calc(j).second.add(j, next[j]);
      fail[j] = fail[next[j]] = 0;
      if (tmp1.F() > tmp2.F())
      {
        //puts("calc1:");
        res = res + calc(j).second;
        Out1(j);
      }
      else
      {
        res = res + tmp2;
        Out1(j);
        AddPair(j, next[j]);
      }
    }

  printf("%d %d\n", res.num, res.good);
  forn(i, sz(p1))
    printf("%d %d\n", p1[i] + 1, p2[i] + 1);
  return 0;
}