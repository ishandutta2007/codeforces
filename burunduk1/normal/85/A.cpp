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

#define NAME "a"

const int maxn = 103;
char s[4][maxn];

int main()
{
  int n;
  cin >> n;
  if (n == 1)
  {
    puts("a");
    puts("a");
    puts("b");
    puts("b");
    return 0;
  }
  if (n == 2)
  {
    puts("aa");
    puts("bb");
    puts("cc");
    puts("dd");
    return 0;
  }
  if (n % 2 == 0)
  {
    forn(i, n / 2)
    {
      s[0][2 * i] = s[0][2 * i + 1] = i % 2 + 'a';
      s[3][2 * i] = s[3][2 * i + 1] = i % 2 + 'c';
    }
    forn(i, n / 2 - 1)
    {
      s[1][2 * i + 2] = s[1][2 * i + 1] = i % 2 + 'e';
      s[2][2 * i + 2] = s[2][2 * i + 1] = i % 2 + 'g';
    }
    s[1][0] = s[2][0] = 'x';
    s[1][n - 1] = s[2][n - 1] = 'y';
  }
  else
  {
    forn(i, n / 2)
    {
      s[0][2 * i] = s[0][2 * i + 1] = i % 2 + 'a';
      s[1][2 * i] = s[1][2 * i + 1] = i % 2 + 'c';
      s[2][2 * i + 2] = s[2][2 * i + 1] = i % 2 + 'e';
      s[3][2 * i + 2] = s[3][2 * i + 1] = i % 2 + 'g';
    }
    s[2][0] = s[3][0] = 'x';
    s[0][n - 1] = s[1][n - 1] = 'y';
  }
  forn(i, 4)
    puts(s[i]);
  return 0;
}