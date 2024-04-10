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

#define maxn 201010
int n;
llong b[maxn];
llong mi[maxn], ma[maxn];
llong ans[maxn];
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n / 2) cin >> b[i];

  int m = n / 2;

  ans[m - 1] = b[m - 1] / 2;
  ans[m] = b[m - 1] - ans[m - 1];
  for (int l = m - 2; l >= 0; --l) {
    int r = n - l - 1;
    ans[l] = min(ans[l + 1], b[l] / 2);
    ans[r] = max(ans[r - 1], (b[l] + 1) / 2);
    if (b[l] - ans[l] < ans[r]) ans[l] = b[l] - ans[r];
    else ans[r] = b[l] - ans[l];
  }
  rep(i, n) cout << ans[i] << ' ';
  return 0;
}