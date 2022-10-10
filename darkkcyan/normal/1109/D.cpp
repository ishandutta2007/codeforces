#include <bits/stdc++.h>
using namespace std;

#define cli clog << "\"" << __PRETTY_FUNCTION__ << "\"@" << __LINE__ << ": "
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }
template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}
template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define rem ((llong)1e9+7)
#define maxn 1010100

llong mpow(llong b, llong m) {
  if (m == -1) m = rem - 2;
  llong ans = 1;
  for (; m > 0; m >>= 1) {
    if (m & 1) (ans *= b) %= rem;
    (b *= b) %= rem;
  }
  return ans;
}

int n, m, a, b;
llong fac[2 * maxn], rfac[2 * maxn];

llong c(llong N, llong K) {
  //cli << N << ' ' << K << endl;
  return fac[N] * rfac[K] % rem * rfac[N - K] % rem;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> a >> b;
  fac[0] = rfac[0] = 1;
  rep(i, 2 * maxn - 1) {
    fac[i + 1] = fac[i] * (i + 1) % rem;
    rfac[i + 1] = mpow(fac[i + 1], rem - 2);
  }

  llong ans = 0;

  rep(i, min(m - 1, n - 2) + 1) {
    llong mid = c(m - 1, i);
    llong cnttree = (i + 2) * mpow(n, n - (i + 2) - 1) % rem;
    llong d = mpow(m, (n - 1) - (i + 1));
    llong e = fac[n - 2] * rfac[n - 2 - i] % rem;
    //clog << i << ' ' << mid << ' ' << cnttree << ' ' << d << endl;
    ans += mid * cnttree % rem * d % rem * e % rem;
    ans %= rem;
  }
  cout << ans;

  return 0;
}