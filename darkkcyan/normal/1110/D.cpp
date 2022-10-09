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

#define maxn 1010100
#define maxs 10
#define inf INT_MAX
int n, m;
int cnt[maxn] = {0};
llong dp[2][maxs][maxs];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) {
    int a; cin >> a;
    cnt[a] ++;
  }
  if (m == 1) {
    cout << cnt[1] / 3;
    return 0;
  }
  llong ans = 0;
  rep1(i, m) {
    int t = cnt[i] / 3;
    cnt[i] %= 3;
    while (t and cnt[i] + 3 < maxs) {
      cnt[i] += 3;
      --t;
    }
    ans += t;
  }

  rep(i, maxs) rep(f, maxs) dp[0][i][f] = -inf;
  rep(i, cnt[1] + 1) rep(f, cnt[2] + 1)  {
    dp[0][i][f] = (cnt[1] - i) / 3 + (cnt[2] - f) / 3;
  }

  for (int i = 3; i <= m; ++i) {
    bool s = i & 1;
    rep(u, maxs) rep(v, maxs) dp[s][u][v] = -inf;
    rep(u, maxs) rep(v, maxs) rep(k, 3) {
      if (k > u or k > v or k > cnt[i]) break;
      dp[s][v - k][cnt[i] - k] = max(dp[s][v - k][cnt[i] - k], dp[!s][u][v] + k + (u - k) / 3);
    }
  }
  llong tm = -inf;
  rep(i, maxs) rep(f, maxs) tm = max(tm, dp[m & 1][i][f] + i / 3 + f / 3);
  ans += tm;
  cout << ans;


  return 0;
}