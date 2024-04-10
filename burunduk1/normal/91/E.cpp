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
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)
#define LAST(a) a[sz(a) - 1]

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef unsigned char byte;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

template <class T> inline T sign( T x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template <class T> inline T myAbs( T a ) { return a > 0 ? a : -a; }

const int maxn = 1 << 19;

int qn, n, a[maxn], b[maxn];
int N, l[maxn], r[maxn];
vector <pii> v[maxn];
int pn, p[maxn];

inline bool pless( int i, int j ) { return mp(b[i], -a[i]) < mp(b[j], -a[j]); }

#define F(i, t) (a[i] + (ll)b[i] * (t))

int ri;
ll Res;

void Add( int i, int t )
{
//  printf("Add(%d,%d) [%d,%d]\n", i, t, l[i], r[i]);
  int j = lower_bound(all(v[i]), mp(t + 1, -1)) - v[i].begin() - 1;
  assert(0 <= j && j < sz(v[i]));
  ll tmp = F(v[i][j].second, t);
  if (tmp > Res)
    Res = tmp, ri = v[i][j].second;
}

int main()
{
  scanf("%d%d", &n, &qn);
  forn(i, n)
    scanf("%d%d", &a[i], &b[i]);

  N = 1;
  while (N < n)
    N *= 2;
  forn(i, N)
    l[N + i] = r[N + i] = i;
  fornd(i, N)
    l[i] = l[2 * i], r[i] = r[2 * i + 1];
  forab(i, 1, 2 * N - 1)
  {
    int L = l[i], R = r[i];
    pn = 0;
    forab(j, L, R)
      p[pn++] = j;
    sort(p, p + pn, pless);

    forn(j, pn)
      if (!j || b[p[j - 1]] != b[p[j]])
      {
        int k = p[j];
        while (sz(v[i]))
        {
          pii &pa = LAST(v[i]); 
          int t = pa.first;
          if (F(k, t) < F(pa.second, t))
            break;
          v[i].pop_back();
        }
        if (!sz(v[i]))
          v[i].pb(mp(0, k));
        else
        {
          int o = LAST(v[i]).second; 
          {
            int t = LAST(v[i]).first;
            assert(F(k, t) < F(o, t));
          }
          assert(a[o] >= a[k]);
          assert(b[k] > b[o]);
          int t = (a[o] - a[k]) / (b[k] - b[o]) + 1;
          v[i].pb(mp(t, k));
        }
      }
  
/*
    printf("%d : [%d, %d] and ", i, L, R);
    forn(j, sz(v[i]))
      printf("(t=%d, a=%d, b=%d) ", v[i][j].first, a[v[i][j].second], b[v[i][j].second]);
    puts("");
*/
  }

  while (qn--)
  {
    int L, R, t;
    scanf("%d%d%d", &L, &R, &t), L--, R--;
    // TODO

    L += N, R += N;
    ri = -1, Res = -1;
    while (L <= R)
    {
      if (L % 2 == 1) Add(L++, t);
      if (R % 2 == 0) Add(R--, t);
      L /= 2, R /= 2;
    }
//    printf("%d : %d\n", ri, Res);
    printf("%d\n", ri + 1);
  }
  return 0;
}