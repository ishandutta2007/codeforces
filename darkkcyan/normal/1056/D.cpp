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
vector<int> gr[maxn];
int cnt[maxn];
int p[maxn];
int cleft[maxn];
set<ii> se;

void dfs(int u) {
  if (len(gr[u]) == 1 and u != 1) {
    cnt[u] = 1;
    se.insert({1, u});
  }
  cleft[u] = len(gr[u]) - (u != 1);
  for (auto v: gr[u]) {
    if (v == p[u]) continue;
    p[v] = u;
    dfs(v);
    cnt[u] += cnt[v];
  }
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  if (n == 1) {
    cout << 1;
    exit(0);
  }
  rep1(i, n - 1) {
    int u; cin >> u;
    gr[u].push_back(i + 1);
    gr[i + 1].push_back(u);
  }

  p[1] = 0;
  dfs(1);
  int ans = 0;
  //clog << "OK" << endl;
  //clog << tovec(se) << endl;
  rep1(i, n) {
    int u = se.begin()->yy;
    ans = max(ans, cnt[u]);
    se.erase(se.begin());
    int par = p[u];
    //clog << u << ' ' << par << ' ' << cleft[par] << endl;
    if (--cleft[par] == 0) {
      se.insert({cnt[par], par});
    }
    cout << ans << ' ';
    //clog << tovec(cleft + 1, cleft + n + 1) << endl;
  }


  return 0;
}