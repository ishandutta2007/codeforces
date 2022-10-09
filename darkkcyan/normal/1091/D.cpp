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

#define rem ((llong)998244353) 
#define maxn 1010101
llong per[maxn];

llong mpow(llong x, llong m) {
  llong ans = 1;
  for (; m > 0; m >>= 1) {
    if (m & 1) (ans *= x) %= rem;
    (x *= x) %= rem;
  }
  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  per[0] = 1;
  rep1(i, maxn - 1) (per[i] = per[i - 1] *  i) %= rem;
  llong n; cin >> n;
  llong ans = per[n];
  for (llong i = 2; i < n; ++i) {
    llong tu = (n - i) * (i - 1) % rem * per[n] % rem;
    llong tv = per[i];
    (ans += tu * mpow(tv, rem - 2) % rem) %= rem;
  }
  cout << ans;

  return 0;
}