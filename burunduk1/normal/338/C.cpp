#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

typedef pair <int, int> pii;
ostream& operator << ( ostream &a, pii p ) { return a << "<" << p.first << "," << p.second << ">"; }

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
#define all(a) (a).begin(), (a).end()

#define DEBUG 0

#if DEBUG
#  define err(...) fprintf(stderr, __VA_ARGS__)
#else
#  define err(...)
#endif

/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.16
 */

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef vector <int> vi;
typedef long long ll;

const ll inf = (ll)1e18;
const int PN = (int)1e6 + 1;
const int N = 8;

int n, pn, p[PN];
ll a[N];

int primeDiv( ll x )
{
  static map <ll, int> ans;
  if (ans.count(x))
    return ans[x];
  int cnt = 0;
  ll x0 = x;
  err("primeDiv(%I64d) = ", x);
  for (int i = 0; i < pn && (ll)p[i] * p[i] <= x; i++)
    while (x % p[i] == 0)
      cnt++, x /= p[i];
  err("%d\n", cnt + (x > 1));
  return ans[x0] = cnt + (x > 1);
}

map <vi, int> f;

inline void relax( int &a, int b )
{
  a = min(a, b);
}

// 0 : unused, 1 : open vertex, 2 : closed vertex
int go( const vi &v )
{
  if (f.count(v))
    return f[v];
  int &res = f[v], cnt = 0, bad = 0;
  forn(i, n)
    if (v[i] == 0)
      bad = 1;
    else 
      cnt += (v[i] == 1);
  if (!bad)
  {
    err("%s : %d\n", cstr(all(v)), cnt > 1);
    return res = (cnt > 1); // join
  }

  int pr = 0;
  res = (int)1e9;
  forn(i, n)
    if (v[i] == 1)
      pr |= 1 << i;
  vi v1 = v;
  err("%s : pr = %d\n", cstr(all(v)), pr);
  forn(i, n)
    if (v[i] == 0)
      for (int j = pr;; j = (j - 1) & pr)
      {
        int cnt = 0;
        v1 = v;
        v1[i] = 1;
        ll mul = 1;
        forn(t, n)
          if ((j >> t) & 1)
          {
            v1[t] = 2, cnt++;
            mul *= min(inf / mul, a[t]);
          }
        err("%s : i = %d, j = %d, mul = %I64d\n", cstr(all(v)), i, j, mul);
        if (a[i] % mul == 0)
        {
          relax(res, go(v1) + 1 + primeDiv(a[i] / mul));
        }
        if (!j)
          break;
      }
  return res;
}

int main()
{
  for (int i = 2; i < PN; i++)
    if (!p[i])
    {
      p[pn++] = i;
      for (int j = i + i; j < PN; j += i)
        p[j] = 1;
    }

  scanf("%d", &n);
  vi v(n);
  int cnt = 0;
  forn(i, n)
  {
    cin >> a[i];
    if (primeDiv(a[i]) == 1)
      v[i] = 1, cnt++;
  }
  
  printf("%d\n", go(v) + cnt);
  return 0;
}