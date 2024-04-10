#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
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
}/*}}}*/

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) {
    llong n, x, y, d; cin >> n >> x >> y >> d;
    llong ans = LLONG_MAX;
    if ((x - y) % d == 0)
      ans = abs(x - y) / d;
    if ((y - 1) % d == 0)
      ans = min(ans, (y - 1) / d + (x - 1 + d - 1) / d);
    if ((n - y) % d == 0)
      ans = min(ans, (n - y) / d + (n - x + d - 1) / d);
    if (ans != LLONG_MAX) cout << ans;
    else cout << -1;
    cout << '\n';
  }


  return 0;
}