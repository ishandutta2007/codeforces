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

#define maxn 500
int h, t, r, n, m;
ii ah[maxn], at[maxn];  // add head, add tail
vector<int> gr[maxn * maxn];
bool zmeyWin[maxn * maxn];
int depth[maxn * maxn];

int state[maxn * maxn];
vector<int> topo;
bool dfs(int u) {
  state[u] = 1;
  if (u % maxn + u / maxn <= r) for (auto v: gr[u]) {
    if (state[v] == 1) {
      return true;
    }
    if (state[v] == 2) continue;
    if (dfs(v)) return true;
  }
  state[u] = 2;
  topo.push_back(u);
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> h >> t >> r;
  cin >> n;
  rep1(i, n) cin >> ah[i].xx >> ah[i].yy;
  cin >> m;
  rep1(i, m) cin >> at[i].xx >> at[i].yy;

  rep(uh, r + 1) rep(ut, r + 1) {
    int u = uh * maxn + ut;
    if (uh + ut > r) zmeyWin[u] = 1;
    rep1(ch, min(uh, n)) {
      int vh = uh - ch + ah[ch].xx;
      int vt = ut + ah[ch].yy;
      int v = vh * maxn + vt;
      gr[u].push_back(v);
    }

    rep1(ct, min(ut, m)) {
      int vh = uh + at[ct].xx;
      int vt = ut - ct + at[ct].yy;
      int v = vh * maxn + vt;
      gr[u].push_back(v);
    }
  }

  int start = h * maxn + t;
  queue<int> qu;
  memset(depth, -1, sizeof(depth));
  depth[start] = 0;
  for (qu.push(start); len(qu); qu.pop()) {
    int u = qu.front();
    //clog << u << endl;
    if (!u) break;
    if (u / maxn + u % maxn > r) continue;
    for (auto v: gr[u]) {
      if (depth[v] != -1) continue;
      depth[v] = depth[u] + 1;
      qu.push(v);
    }
  }
  //clog << "OK" << endl;

  if (depth[0] != -1) {
    cout << "Ivan\n" << depth[0] << '\n';
    return 0;
  }

  if (dfs(start)) {
    cout << "Draw";
    return 0;
  }

  //  reuse depth array
  memset(depth, 0, sizeof(depth)); 
  depth[start] = 0;
  int ans = 0;
  for (; len(topo); topo.pop_back()) {
    int u = topo.back();
    //clog << u /maxn << ' ' << u % maxn << ' ' << depth[u] << endl;
    if (u / maxn + u % maxn > r) {
      ans = max(ans, depth[u]);
      continue;
    }
    //clog << ans << endl;
    for (auto v: gr[u]) depth[v] = max(depth[v], depth[u] + 1);
  }

  cout << "Zmey\n" << ans;

  return 0;
}