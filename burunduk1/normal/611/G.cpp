/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MOD = 1e9 + 7;

inline void add( ll &a, ll b ) { a += b; a %= MOD; }
inline void sub( ll &a, ll b ) { a -= b; a %= MOD; }
inline ll mul( ll a, ll b ) { return (ll)a * b % MOD; }

const int N = 1e6 + 10;

struct pnt {
  ll x, y;

  pnt( ll _x = 0, ll _y = 0 ) : x(_x), y(_y) { }

  inline pnt operator + ( const pnt &p ) const { return pnt(x + p.x, y + p.y); }
  inline pnt operator - ( const pnt &p ) const { return pnt(x - p.x, y - p.y); }
  inline pnt& operator += ( const pnt &p ) { add(x, p.x), add(y, p.y); return *this; }
  inline pnt& operator -= ( const pnt &p ) { sub(x, p.x), sub(y, p.y); return *this; }
  inline pnt operator * ( const int &k ) const { return pnt(x * k, y * k); }
  inline pnt operator / ( const int &k ) const { return pnt(x / k, y / k); }
  inline ll operator * ( const pnt &p ) const { return x * p.y - y * p.x; }
  inline ll operator ^ ( const pnt &p ) const { return x * p.x + y * p.y; }
  void out() { printf("(%lld,%lld) ", x, y); }

} p[3 * N];

ll get( int i, int j, int k ) {
  return (p[j] - p[i]) * (p[k] - p[j]);
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  forn(i, n) 
    cin >> p[i].x >> p[i].y;

  ll s = 0;
  forn(i, n) 
    s += p[i] * p[(i + 1) % n];
  if (s < 0) {
    s = -s;
    reverse(p, p + n);
  }
  forn(i, n) 
    p[i + 2 * n] = p[i + n] = p[i];

  struct Calc {
    ll sum, s;
    pnt diff, diff2;
    Calc() : sum(0), s(0) { }
    void inc_r( int l, int r ) {
      s += get(l, r, r + 1);
      assert(s >= 0);
      add(sum, s);
      diff2 += p[r + 1] - p[r];
      diff -= diff2;
    }
    void inc_l( int l, int r ) {
      s -= get(l, l + 1, r);
      pnt dp = p[l + 1] - p[l];
      diff2 -= dp;
      diff += dp * (r - l);
      add(sum, dp * diff);
    }
  } c1, c2;

  ll res = 0;
  int r1 = 0, r2 = 0;
  forn(l, n) {
    while (r1 - l < n && abs(c1.s + get(l, r1, r1 + 1)) <= s / 2) {
      //printf("i = %d, r1 = %d, s = %lld, c1 = %lld, sum = %lld, ratio = %.4f, ", l, r1, s, c1.s, c1.sum, 1. * s / c1.s), c1.diff.out(), c1.diff2.out(), puts("");
      c1.inc_r(l, r1++);
    }
    //printf("i = %d, r1 = %d, s = %lld, c1 = %lld, sum = %lld, ratio = %.4f, ", l, r1, s, c1.s, c1.sum, 1. * s / c1.s), c1.diff.out(), c1.diff2.out(), puts("");
    assert(r1 - l <= n - 2);
    while (r2 - l < n - 2)
      c2.inc_r(l, r2++);

    ll mid = (2 * c1.s == s ? s / 2 : 0LL);
    ll big = c2.sum - c1.sum;
    ll small = (c1.sum - mid);
    add(res, big - small);

    c1.inc_l(l, r1);
    c2.inc_l(l, r2);
  }
  cout << ((res) % MOD + MOD) % MOD << endl;
  return 0;
}