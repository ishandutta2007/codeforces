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

#define maxn 1010
int n;
ii a[maxn], b[maxn];
set<ii> sb;
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i].xx >> a[i].yy;
  rep(i, n) {
    cin >> b[i].xx >> b[i].yy;
    sb.insert(b[i]);
  }

  //clog << tovec(sb) << endl;
  rep(i, n) {
    ii ans = {a[0].xx + b[i].xx, a[0].yy + b[i].yy};
    set<ii> tsb;
    rep(f, n) {
      tsb.insert({ans.xx - a[f].xx, ans.yy - a[f].yy});
    }
    //clog << tovec(tsb) << endl;
    if (tsb == sb) {
      cout << ans.xx << ' ' << ans.yy;
      return 0;
    }
  }
  assert(false);

  return 0;
}