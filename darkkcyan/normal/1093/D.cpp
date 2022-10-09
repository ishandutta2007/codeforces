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

#define maxn 3010101
#define rem ((llong) 998244353 )

llong p2[maxn];
void calp2() {
  p2[0] = 1;
  rep1(i, maxn - 1) {
    p2[i] = (p2[i - 1] * 2) % rem;
  }
}

int n, m;
vector<int> gr[maxn];
int cnt[2];
int side[maxn];

bool bfs(int u) {
  queue<int> qu;
  qu.push(u);
  cnt[0] = 1;
  cnt[1] = 0;
  side[u] = 0;
  for (; len(qu); qu.pop()) {
    u = qu.front();
    for (auto v: gr[u]) {
      if (side[v] == side[u]) {
        return 0;
      }
      if (side[v] != -1) continue;
      side[v] = !side[u];
      qu.push(v);
      ++cnt[side[v]];
    }
  }
  return 1;
}
queue<int> qu;

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  calp2();
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    rep1(i, n) gr[i].clear();
    while (m--) {
      int u, v; cin >> u >> v;
      gr[u].push_back(v);
      gr[v].push_back(u);
    }
    llong ans = 1;
    memset(side, -1, (n + 10) * sizeof(int));
    rep1(i, n) {
      if (side[i] != -1) continue;
      if (!bfs(i)) {
        ans = 0;
        break;
      }
      (ans *= (p2[cnt[0]] + p2[cnt[1]]) % rem) %= rem;
    }
    cout << ans << '\n';
  }


  return 0;
}