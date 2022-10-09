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
int n, m;
vector<int> gr[maxn];

int low[maxn], num[maxn], cur = 0;

int root = 1;
vector<ii> edges;
bool hasBridge(int u, int p) {
  low[u] = num[u] = cur++;
  for (auto v: gr[u]) {
    if (v == p) continue;
    if (num[v] == -1) {
      edges.push_back({u, v});
      if (hasBridge(v, u)) return true;
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], num[v]);
      if (num[u] > num[v]) edges.push_back({u, v});
    }
  }
  if (low[u] == num[u] and u != root) return true;
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, m) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  
  memset(num, -1, sizeof(num));
  if (hasBridge(1, 1)) {
    cout << 0;
  } else {
    for (auto i: edges) cout << i.xx << ' ' << i.yy << '\n';
  }

  return 0;
}