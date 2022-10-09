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

#define maxn 101010
int n;
llong c;
llong p[maxn], s[maxn];
llong dp[2][maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> c;
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> s[i];
  memset(dp[1], 0, sizeof(dp[1]));
  rep(i, n) {
    bool st = i & 1;
    dp[st][0] = dp[!st][0] + p[i];
    dp[st][i + 1] = dp[!st][i] + s[i];
    rep1(f, i) {
      dp[st][f] = min(
          dp[!st][f - 1] + s[i], 
          dp[!st][f] + p[i] + (llong)f * c
      );
    }
    //cli << tovec(dp[st], dp[st] + i + 2) << endl;
  }
  llong ans = LLONG_MAX;
  rep(i, n + 1) {
    ans = min(ans, dp[~n & 1][i]);
  }
  cout << ans;

  return 0;
}