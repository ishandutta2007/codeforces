/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.16
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define DEBUG 0

#if DEBUG
#  define err(...) fprintf(stderr, __VA_ARGS__)
#else
#  define err(...)
#endif

typedef long long ll;
typedef long double dbl;

inline bool Eq( ll a, ll b, ll mod ) { return (a - b) % mod == 0; }
inline ll Add( ll a, ll b, ll mod ) { a += b; return a >= mod ? a - mod : a; }
inline ll Sub( ll a, ll b, ll mod ) { a -= b; return a < 0 ? a + mod : a; }
inline ll Mul( ll a, ll b, ll m )
{
  ll k = (ll)((dbl)a * b / m);
  ll r = a * b - m * k;
  while (r < 0)
    r += m;
  while (r >= m)
    r -= m;
  return r;
}
inline ll Sqr( ll a, ll mod ) { return Mul(a, a, mod); }

ll Pow( ll x, ll n, ll mod )
{
  ll r = mod > 1 ? 1 : 0;
  for (; n; n /= 2)
  {
    if (n & 1)
      r = Mul(r, x, mod);
    x = Mul(x, x, mod);
  }
  return r;
}

ll Euclid( ll a, ll b, ll &x1, ll &y1 ) // a * x + b * y = gcd
{
  ll d1 = a; x1 = 1, y1 = 0;
  ll d2 = b, x2 = 0, y2 = 1; 
  while (d2 != 0) 
  {
    ll k = d1 / d2;
    ll x3 = x1 - x2 * k, y3 = y1 - y2 * k, d3 = d1 - d2 * k;
    x1 = x2, y1 = y2, d1 = d2;
    x2 = x3, y2 = y3, d2 = d3;
  }
  return d1; // gcd
}

ll Inv( ll a, ll m ) // x * a + y * m == 1
{
  ll x, y;
  Euclid(m, a, y, x);
  return x < 0 ? x + m : x;
}


const int K = (int)1e4;
const ll inf = (ll)1e18;

ll n, m, a[K], deg[K];
ll ans = 0, mod = 1;
int k;

inline ll mul( ll a, ll b )
{
  return a * min(inf / a, b);
}

void Assert( bool f )
{
  if (!f)
  {
    puts("NO");
    exit(0);
  }
}

void KTO( ll a2, ll m2 )
{
  err("KTO: mod = %I64d, rest = %I64d\n", m2, a2);
  ll a1 = ans, m1 = mod;
  mod = m1 * m2;
  ll c1 = Mul(m2, Inv(m2, m1), mod);
  ll c2 = Mul(m1, Inv(m1, m2), mod);
  err("a1 = %I64d, c1 = %I64d, a2 = %I64d, c2 = %I64d\n", a1, c1, a2, c2);
  ans = Add(Mul(a1, c1, mod), Mul(a2, c2, mod), mod);
  err("KTO: mod = %I64d, rest = %I64d [result]\n", mod, ans);
}

void check( ll p )
{
  err("check: p = %I64d\n", p);
  ll ma = -1;
  int pos = 0;
  forn(i, k)
  {
    deg[i] = 1;
    while (a[i] % p == 0)
      deg[i] *= p, a[i] /= p;
    if (deg[i] > ma)
      ma = deg[i], pos = i;
  }

  err("check: p = %I64d, ma = %I64d, pos = %d\n", p, ma, pos);
  forn(i, k)
    if (deg[i] < __gcd((ll)abs(pos - i), ma))
    {
      err("failed on i = %d\n", i);
      Assert(0);
    }

  KTO((ma - pos % ma) % ma, ma);
}

int main()
{
  ll lcm = 1;
  cin >> n >> m >> k;
  forn(i, k)
  {
    scanf("%I64d", &a[i]);
    lcm = mul(lcm / __gcd(lcm, a[i]), a[i]);
  }
  err("lcm = %I64d\n", lcm);
  Assert(lcm <= n);

  ll x = lcm;
  for (int i = 2; (ll)i * i <= x; i++)
    if (x % i == 0)
    {
      while (x % i == 0)
        x /= i;
      check(i);
    }
  if (x > 1)
    check(x);
  err("ans = %I64d\n", ans);
  if (ans == 0)
    ans = mod;
  Assert(ans + k - 1 <= m);
/*
  forn(i, k)
    printf("%I64d ", __gcd(lcm, ans + i));
  puts("");
*/
  puts("YES");
  return 0;
}