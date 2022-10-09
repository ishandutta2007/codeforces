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

#define rem ((llong) 1e9+7)
map<llong, int> getdivs(llong x) {
  map<llong, int> ans;
  for (llong i = 2; i * i <= x; ++i) {
    if (x % i) continue;
    while (x % i == 0) {
      ans[i]++;
      x /= i;
    }
  }
  if (x) ans[x] = 1;

  return ans;
}

llong n, k;

llong mpow(llong x, llong b) {
  llong ans = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) (ans *= x) %= rem;
    (x *= x) %= rem;
  }
  return ans;
}

#define maxk 10100
llong dp[60];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  auto divs = getdivs(n);

  llong ans = 1;

  for (auto x: divs) {
    llong u = x.xx;
    int cnt = x.yy;
    //clog << x << endl;
    llong t = 1;

    rep(i, cnt + 1) {
      dp[i] = t;
      t *= u;
    }

    rep1(_, k) {
      rep1(i, cnt) (dp[i] += dp[i - 1]) %= rem;
      rep1(i, cnt) (dp[i] *= mpow(i + 1, rem - 2)) %= rem;
    }
    //clog << dp[cnt] << endl;
    (ans *= dp[cnt]) %= rem;
  }

  cout << ans;

  return 0;
}