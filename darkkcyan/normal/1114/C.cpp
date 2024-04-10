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

llong cntdiv(llong nfac, llong b) {
  if (nfac == 0) return 0;
  return nfac / b + cntdiv(nfac / b, b);
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong n, b; cin >> n >> b;
  
  llong ans = LLONG_MAX;
  for (llong i = 2; i * i <= b; ++i) {
    if (b % i) continue;
    llong t = 0;
    for (; b % i == 0; b /= i, ++t);
    ans = min(ans, cntdiv(n, i) / t);
  }

  if (b > 1) ans = min(ans, cntdiv(n, b));
  
  cout << ans;

  return 0;
}