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

const int maxk = 100;

ll n, sum = 0;
int k, a[maxk];

int cnt = 0, size = 0;

const int M = 50000;

ll ind, res[maxk][M][2];

ll go( int i, ll pr, int sgn )
{
  if (i == k)
    return pr * sgn;

  #define MEM res[i][pr][(sgn + 1) >> 1]
  if (pr < M && MEM != ind)
    return MEM;
  cnt++;

  ll sum = 0;
  if (i == k)
    sum = pr * sgn;
  else
  {
    sum = go(i + 1, pr, sgn);
    if (pr >= a[i])
      sum += go(i + 1, pr / a[i], -sgn);
  }

  if (pr >= M)
    return sum;
  size++;
  return MEM = sum;
}

int main()
{
  cin >> n >> k;
  forn(i, k)
    cin >> a[i];
  sort(a, a + k);
  reverse(a, a + k);
  memset(res, 0x1234, sizeof(res));
  ind = res[0][0][0];
  cout << go(0, n, 1) << endl;
/*
  fprintf(stderr, "k = %d\n", k);
  fprintf(stderr, "size = %d\n", size);
  fprintf(stderr, "cnt  = %d\n", cnt);
*/
  return 0;
}