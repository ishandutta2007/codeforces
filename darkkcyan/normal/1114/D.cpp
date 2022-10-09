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

#define maxn 5050
int n;
int a[maxn];
int dp[maxn][maxn];

int process(int l, int r) {
  if (l == r) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  if (a[l] == a[r]) return dp[l][r] = process(l + 1, r - 1) + 1;
  return dp[l][r] = min(process(l, r - 1), process(l + 1, r)) + 1;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  n = (int)(unique(a, a + n) - a);
  //clog << tovec(a, a + n) << endl;
  memset(dp, -1, sizeof(dp[0]) * (n + 5));
  cout << process(0, n - 1);
  //rep(i, n) clog << tovec(dp[i], dp[i] + n) << endl;

  return 0;
}