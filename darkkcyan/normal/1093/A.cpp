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

int d[111];
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  memset(d, -1, sizeof(d));
  d[0] = 0;
  queue<int> qu;
  for (qu.push(0); len(qu); qu.pop()) {
    int u = qu.front();
    for (int i = 2; i <= 7; ++i) {
      int v = u + i;
      if (d[v] != -1) continue;
      d[v] = d[u] + 1;
      qu.push(v);
    }
  }

  int t; cin >> t;
  while (t--) {
    int u; cin >> u;
    cout << d[u] << '\n';
  }

  return 0;
}