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

int n, p[maxn];
string a[maxn], b[maxn];

int F( string s )
{
  if (s == "rat") return 0;
  if (s == "woman" || s == "child") return 1;
  if (s == "man") return 2;
  return 3;
}

bool pless( int i, int j )
{
  if (F(b[i]) != F(b[j]))
    return F(b[i]) < F(b[j]);
  return i < j;
}

int main()
{
  int n;
  cin >> n;
  forn(i, n)
    cin >> a[i] >> b[i], p[i] = i;
  sort(p, p + n, pless);
  forn(i, n)
    cout << a[p[i]] << endl;
  return 0;
}