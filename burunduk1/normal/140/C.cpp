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
#include <bitset>
#include <numeric>
#include <iterator>

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
#define uni(a) (unique(all(a)) - (a).begin());

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)
#define LAST(a) a[sz(a) - 1]
#define ONE(n) ((1 << (n)) - 1)

typedef unsigned int uint;
typedef double dbl;
typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef unsigned char byte;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }
template <class T> inline T sign( T x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template <class T> inline T myAbs( T a ) { return a > 0 ? a : -a; }

template <class T> string str( T i ) { stringstream ss; ss << i; return ss.str(); }
string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

template <class T> string str( T begin, T end )
{
  stringstream ss;
  ss << "[";
  int f = 0;
  while (begin != end)
    ss << (f ? ", " : "") << *begin++, f = 1;
  ss << "]";
  return ss.str();
}
template <class T> string str( int n, T begin ) { return str(begin, begin + n); }
#define cstr(...) str(__VA_ARGS__).c_str()

#define DEBUG 1
void err( const char *fmt, ... )
{
  #if DEBUG
  va_list list;
  va_start(list, fmt);
  vfprintf(stderr, fmt, list);
  fflush(stderr);
  #endif
}

void Assert( bool f, const char *fmt, ... )
{
  if (!f)
  {
    va_list list;
    va_start(list, fmt);
    vfprintf(stderr, fmt, list);
    fflush(stderr);
    exit(1);
  }
}

/* The main part */

vi a1, b1, c1;
int n, x;
map <int, int> cnt;
set <pii> b;

void add( pii p )
{
  if (p.first > 1)
    b.insert(mp(p.first - 1, p.second));
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &x), cnt[x]++;
  forit(it, cnt)
    b.insert(mp(it->second, it->first));
  while (sz(b) >= 3)
  {
    set <pii>::const_reverse_iterator it = b.rbegin();
    pii A = *it++;
    pii B = *it++;
    pii C = *it++;
    int a[] = {A.second, B.second, C.second};
    sort(a, a + 3);
    a1.pb(a[2]), b1.pb(a[1]), c1.pb(a[0]);
    b.erase(A);
    b.erase(B);
    b.erase(C);
    add(A);
    add(B);
    add(C);
  }
  printf("%d\n", sz(a1));
  forn(i, sz(a1))
    printf("%d %d %d\n", a1[i], b1[i], c1[i]);
  return 0;
}