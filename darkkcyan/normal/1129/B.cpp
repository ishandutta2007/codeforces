#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
#define _pt(x) typename iterator_traits<x>::value_type
template<class u> vector<_pt(u)> tovec(u a, u b) { return vector<_pt(u)>(a, b); }
template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  rep(i, len(a)) cout << a[i] << (i == len(a) - 1 ? "" : ", ");
  return cout << "]";
}
template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << a.xx << ": " << a.yy;
}/*}}}*/

#define maxa ((llong)1e6)
llong k;
bool ok(llong l, llong s) {
  return (k + l * s) % (l - 1) == 0 and abs((k + l * s) / (l - 1)) <= maxa;
}
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> k;
  
  for (int l = 2; l <= 2000; ++l) rep1(s, l - 1)
    if (ok(l, s)) {
      llong a = (k + l * s) / (l - 1);
      cout << l << '\n';
      rep(i, l - s - 1) cout << 0 << ' ';
      rep(i, s) cout <<  -1 << ' ';
      cout << a;
      
      return 0;
    }

  cout << -1 << endl;

  return 0;
}