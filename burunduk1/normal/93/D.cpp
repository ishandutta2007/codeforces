/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

/* Template */

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

/* The main part */

const int MOD = ((int)1e9 + 7) * 2;

inline ll dif( ll a, ll b )
{
  if ((a -= b) < 0)
    a += MOD;
  return a;
}

inline ll sum( ll a, ll b )
{
  if ((a += b) >= MOD)
    a -= MOD;
  return a;
}

typedef ll matrix[16][16];

const ll maxPow = 32;

matrix m, res, tmp, E;
matrix m1[maxPow];
matrix m2[maxPow];

void Add( matrix res, matrix a, matrix b )
{
  forn(i, 16)
    forn(j, 16)
      res[i][j] = sum(a[i][j], b[i][j]);
}

void Mul( matrix res, matrix a, matrix b )
{
  matrix c;
  memset(c, 0, sizeof(matrix));
  forn(i, 16)
    forn(k, 16)
      forn(j, 16)
        c[i][j] += (((ll)a[i][k] * b[k][j]) % MOD), c[i][j] %= MOD;
  memcpy(res, c, sizeof(matrix));
}

void Pow( ll n )
{
  matrix tmp, tmp2;
  n++;

  memset(res, 0, sizeof(matrix));
  memcpy(tmp, E, sizeof(matrix));
  for (ll i = 0; i < maxPow; i++)
    if ((n >> i) & 1)
    {
      Mul(tmp2, tmp, m2[i]);
      Add(res, res, tmp2);
      Mul(tmp, tmp, m1[i + 1]);
    }
}

ll G( ll N )
{
  if (N == 0)
    return 0;
  if (N == 1)
    return 4;

  ll is[16];
  memset(is, 0, sizeof(is));
  forn(b, 4)
    forn(c, 4)
    {
      ll bad = 0;
      if (b == c)
        bad = 1;
      if ((b == 0 && c == 1) || (b == 1 && c == 0))
        bad = 1;                 
      if ((b == 2 && c == 3) || (b == 3 && c == 2))
        bad = 1;
      is[(b << 2) + c] = !bad;
    }

  Pow(N - 2);

  ll x = 4;
  forn(i, 16)
    if (is[i])
      forn(j, 16)
        x = sum(x, res[i][j]);
  return x;
}

ll A( ll N )
{
  ll x = 0;
  x = sum(x, G(N));
  x = sum(x, G((N + 1) / 2));
  return x / 2;
}

ll Solve()
{
  ll L, R;
  cin >> L >> R;
  return dif(A(R), A(L - 1));
}

int main()
{
  forn(a, 4)
    forn(b, 4)
      forn(c, 4)
      {
        ll bad = 0;
        if (b == c)
          bad = 1;
        if ((b == 0 && c == 1) || (b == 1 && c == 0))
          bad = 1;                 
        if ((b == 2 && c == 3) || (b == 3 && c == 2))
          bad = 1;
        if (a == 2 && b == 0 && c == 3)
          bad = 1;
        if (a == 3 && b == 0 && c == 2)
          bad = 1;
        m[(a << 2) + b][(b << 2) + c] = !bad;
      }
  
  memset(E, 0, sizeof(matrix));
  forn(i, 16)
    E[i][i] = 1;

  memcpy(m1[0], E, sizeof(matrix));
  memcpy(m1[1], m, sizeof(matrix));
  for (ll i = 2; i < maxPow; i++)
    Mul(m1[i], m1[i - 1], m1[i - 1]);
  
  memcpy(m2[0], E, sizeof(matrix));
  for (ll i = 1; i < maxPow; i++)
  {
    Mul(m2[i], m2[i - 1], m1[i]);
    Add(m2[i], m2[i], m2[i - 1]);
  }

  cout << Solve() % (MOD / 2) << endl;
  return 0;
}