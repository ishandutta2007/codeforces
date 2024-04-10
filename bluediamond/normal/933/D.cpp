#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

const ll M = (ll)1e9 + 7;
const ll I2 = 500000004;
const ll I6 = 166666668;
const ll I30 = 233333335;

ll rep(ll x) {
  x %= M;
  if (x < 0)x += M;
  return x;
}

ll add(ll a, ll b) {
  a = rep(a);
  b = rep(b);
  return rep(a + b);
}

ll mul(ll a, ll b) {
  a = rep(a);
  b = rep(b);
  return rep(a * b);
}

void addup(ll& a, ll b) {
  a = add(a, b);
}

void mulup(ll& a, ll b) {
  a = mul(a, b);
}

ll pw(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

ll dv(ll a, ll b) {
  return mul(a, pw(b, M - 2));
}

ll gauss(ll n) {

  return mul(n, n + 1);
}

ll sqgauss(ll n) {
  return mul(n, mul(n + 1, 2 * n + 1));
}



ll get_sqrt(ll x) {
  ll r = sqrt(x);
  while (r * r > x)r--;
  while ((r + 1) * (r + 1) <= x) r++;
  assert(r * r <= x);
  assert((r + 1) * (r + 1) > x);
  return r;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }



  ll n, A = 0, B = 0;
  cin >> n;

  ll dim = get_sqrt(n), cnt = 0;


  ll C = 0;

  for (ll x = -dim; x <= +dim; x++) {
    assert(x * x <= n);
    ll ymax = get_sqrt(n - x * x);
    addup(cnt, 2 * ymax + 1);
    addup(A, mul(mul(2, 2 * ymax + 1), pw(x, 4)));
    addup(A, mul(-mul(2, 2 * ymax + 1), pw(x, 2)));

    ll ff = 0;
    ll trol = 0;

    addup(trol, mul(mul(2, 2 * ymax + 1), pw(x, 4)));

    ll inner = 0;

    addup(inner, mul(I6, sqgauss(ymax)));
    mulup(inner, mul(2, pw(x, 2)));
    addup(inner, mul(mul(ymax, mul(ymax + 1, mul(2 * ymax + 1, 3 * ymax * ymax + 3 * ymax - 1))), I30));
    mulup(inner, 2);

    addup(inner, mul(2 * ymax + 1, pw(x, 4)));

    addup(C, mul(pw(x, 2), inner));

    addup(trol, mul(mul(4, mul(I6, sqgauss(ymax))), pw(x, 2)));
    addup(B, -trol);
    ff = mul(2, mul(I6, sqgauss(ymax)));
    mulup(ff, mul(2, pw(x, 2)));
    addup(A, ff);
  }

  addup(B, mul(C, 2));
  mulup(B, 2);
  addup(B, -A);


  swap(A, B);
  mulup(A, -1);
  mulup(B, -1);
  addup(A, mul(cnt, sqgauss(n)));
  addup(B, mul(cnt, gauss(n)));
  ll sol = 0;
  addup(sol, mul(-I6, A));
  addup(sol, mul(mul(n + 1, I2), B));

  cout << sol << "\n";
}