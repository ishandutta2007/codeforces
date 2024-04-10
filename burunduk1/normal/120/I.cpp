/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

/* Template */

#include <cstdarg>
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

typedef unsigned int uint;
typedef double dbl;
typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef unsigned char byte;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

template <class T> inline T sign( T x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template <class T> inline T myAbs( T a ) { return a > 0 ? a : -a; }

#define DEBUG 1
void err( const char *fmt, ... )
{
  #if DEBUG
  va_list list;
  va_start(list, fmt);
  vfprintf(stderr, fmt, list);
  #endif
}

/* The main part */

const int maxN = (int)2e6 + 10;

int is[10][7] = 
{
  {1, 0, 1, 1, 1, 1, 1}, // 0
  {0, 0, 0, 1, 1, 0, 0}, // 1
  {1, 1, 1, 0, 1, 1, 0}, // 2
  {1, 1, 1, 1, 1, 0, 0}, // 3
  {0, 1, 0, 1, 1, 0, 1}, // 4
  {1, 1, 1, 1, 0, 0, 1}, // 5
  {1, 1, 1, 1, 0, 1, 1}, // 6
  {0, 0, 1, 1, 1, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 1, 0, 1}, // 9
};
int c[10][10], val[10];

char s[maxN];
int n, k;

int main()
{
  forn(i, 10)
    forn(j, 10)
      forn(k, 7)
        c[i][j] += (is[i][k] && is[j][k]);
  forn(i, 10)
    val[i] = c[i][i];

  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));

  gets(s);
  k = strlen(s);
  n = k / 2;
  forn(i, k)
    s[i] -= '0';

  int sum0 = 0;
  forn(i, n)
    sum0 += c[s[i]][s[i + n]];

  int cur = sum0;
  fornd(i, k)
  {
    cur -= (i < n ? val[s[i]] : c[s[i - n]][s[i]]);
    forab(d, s[i] + 1, 9)
    {
      int old = s[i]; s[i] = d;
      int sum = cur + (i < n ? val[d] : c[s[i - n]][d]);

      if (sum > sum0)
      {
        //printf("i = %d, d = %d, sum = %d, sum0 = %d\n", i, d, sum, sum0);
        forab(j, i + 1, 2 * n - 1)
        {
          sum -= j < n ? 7 : val[s[j - n]];
          int bad = 1;
          forn(d, 10)
          {
            int x = j < n ? val[d] : c[s[j - n]][d];
            if (sum + x > sum0)
              sum += x, s[j] = d, d = 10, bad = 0;
          }
          assert(!bad);
        }
        forn(i, k)
          printf("%d", s[i]);
        puts("");
        return 0;
      }
      
      s[i] = old;
    }
    cur += (i < n ? 7 : val[s[i - n]]);
  }
  puts("-1");
  return 0;
}