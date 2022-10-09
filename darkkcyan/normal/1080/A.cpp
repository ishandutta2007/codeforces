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
  llong n, k; cin >> n >> k;

  llong nr = 2 * n;
  llong ng = 5 * n;
  llong nb = 8 * n;

  nr = (nr + k - 1) / k;
  ng = (ng + k - 1) / k;
  nb = (nb + k - 1) / k;
  clog << nr << ' ' << ng << ' ' << nb << endl;
  cout << nr + ng + nb;


  return 0;
}