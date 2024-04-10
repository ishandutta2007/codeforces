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
#define forabd(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
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

int sign( int x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }

const int maxn = 103;

int n, a[maxn], b[maxn], c[maxn];

void Fill( int *cnt, int a )
{
  forn(i, 4)
    cnt[a % 10]++, a /= 10;
}

int Cor( int *cnt )
{
  forn(i, 10)
    if (cnt[i] > 1)
      return 0;
  return 1;
}

int main()
{
  cin >> n;
  forn(i, n)
    cin >> a[i] >> b[i] >> c[i];

  int cnt = 0, res = -1;
  forn(x, 10000)
  {
    int good = 0;
    forn(i, n)
    {
      int cnt1[10], cnt2[10];
      zero(cnt1), zero(cnt2);
      Fill(cnt1, a[i]);
      Fill(cnt2, x);
      if (!Cor(cnt2))
        continue;

      int tmp1 = 0, tmp2 = 0;
      forn(j, 10)
        tmp1 += min(cnt1[j], cnt2[j]);

      int A = a[i], X = x;
      forn(j, 4)
        tmp2 += (A % 10 == X % 10), A /= 10, X /= 10;
      good += (tmp2 == b[i] && tmp1 == b[i] + c[i]);
    }
    if (good == n)
      res = x, cnt++;
  }

  if (!cnt)
    puts("Incorrect data");
  else if (cnt > 1)
    puts("Need more data");
  else
    printf("%04d\n", res);
  return 0;
}