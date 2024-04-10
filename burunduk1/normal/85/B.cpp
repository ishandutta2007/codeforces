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

multiset <ll> fr[3];
int k[3], t[3], n, a[maxn];

int main()
{
  forn(i, 3)
    scanf("%d", &k[i]);
  forn(i, 3)
    scanf("%d", &t[i]);
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a[i]);
  sort(a, a + n);

  forn(j, 3)
    forn(i, min(k[j], n))
      fr[j].insert(0);

  ll res = 0;
  forn(i, n)
  {
    ll cur = a[i];
    //fprintf(stderr, "%d -> %I64d\n", a[i], cur);
    forn(j, 3)
    {
      assert(fr[j].size() >= 1);
      //fprintf(stderr, "%I64d, %d\n", *fr[j].begin(), t[j]);
      cur = max(cur, *fr[j].begin()) + t[j];
      fr[j].erase(fr[j].begin());
      fr[j].insert(cur);
    }
    //fprintf(stderr, "%d -> %I64d\n", a[i], cur);
    res = max(res, cur - a[i]);
  }
  cout << res << endl;
  return 0;
}