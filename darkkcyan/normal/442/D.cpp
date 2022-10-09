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

#define maxn 1010100
int n;
int p[maxn];
int dp[maxn];
multiset<int> maxChild[maxn];
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 2; i <= n + 1; ++i) {
    cin >> p[i];
    dp[i] = 1;
    for (int u = i; u != 1; u = p[u]) {
      int v = p[u];
      maxChild[v].insert(dp[u]);
      if (len(maxChild[v]) > 2) maxChild[v].erase(maxChild[v].begin());
      int newVal = *maxChild[v].begin();
      if (len(maxChild[v]) > 1) newVal = max(newVal + 1, *maxChild[v].rbegin());
      assert(newVal >= dp[v]);
      if (newVal == dp[v]) break;
      dp[v] = newVal;
    }
    cout << *maxChild[1].rbegin() << ' ';
  }

  return 0;
}