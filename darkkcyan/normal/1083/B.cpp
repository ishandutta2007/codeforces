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

#define maxn 501010
#define inf ((llong)1e10)

int n;
llong k;
string s, t;
llong lv[maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> k >> ws;
  cin >> s >> t;

  if (k == 1) {
    cout << n;
    exit(0);
  }

  int beg = 0;
  while (beg < n and s[beg] == t[beg]) ++beg;
  if (beg == n) {
    cout << n;
    exit(0);
  }

  llong ans = (n - beg) * 2 + beg;
  k -= 2;

  for (int i = beg + 1; i < n; ++i) {
    if (s[i] == 'a') {
      lv[n - i]++;
    }
    if (t[i] == 'b') {
      lv[n - i]++;
    }
    lv[n - i] = min(lv[n - i] + lv[n - i + 1] * 2ll, inf);
  }

  llong minus = 0;
  for (int i = n + 1; i-- > 1;) {
    lv[i] -= minus;
    //clog << i << ' ' << lv[i] << endl;
    llong x = min(k, lv[i]);
    k -= x;
    ans += x * (llong)i;
    if (k == 0) break;
    minus += x;
  }

  cout << ans;

  return 0;
}