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

#define maxn 101010
int n;
int p[maxn], h[maxn];
int s[maxn];
vector<int> gr[maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  h[1] = 1;
  p[1] = 1;
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
    h[i] = h[p[i]] + 1;
    gr[p[i]].push_back(i);
  }

  rep1(i, n) {
    cin >> s[i];
  }

  llong ans = s[1];
  rep1(u, n) {
    if (s[u] != -1) continue;
    if (len(gr[u]) == 0) continue;
    int ms = s[gr[u][0]];
    llong sums = 0;
    for (auto v: gr[u]) {
      //clog << ms << ' ' << s[v] << endl;
      ms = min(ms, s[v]);
      sums += s[v];
    }
    //clog << u << ' ' << ms << ' ' << gr[u] << endl;
    if (ms < s[p[u]]) {
      cout << -1;
      return 0;
    }

    ans += ms - s[p[u]] + sums - ms * len(gr[u]);
  }
  cout << ans;

  return 0;
}