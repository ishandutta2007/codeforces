#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

vector<int> _elist1[300005];
vector<int> elist[300005];

int qa[300005], qb[300005];

bool vis[300005];
void getspanningtree(int u) {
  for (int v : _elist1[u])
    if (!vis[v]) {
      vis[v] = 1;
      elist[u].pb(v);
      elist[v].pb(u);
      getspanningtree(v);
    }
}

vector<int> path;
bool seekpath(int v, int f, int targ) {
  if (v == targ) {
    path.push_back(targ);
    return 1;
  }
  for (int u : elist[v])
    if (u != f) {
      if (seekpath(u, v, targ)) {
        path.push_back(v);
        return 1;
      }
    }
  return 0;
}
vector<int> getpath(int u, int v) {
  path.clear();
  // cout << u << ' ' << v << endl;
  seekpath(u, -1, v);
  reverse(all(path));
  // for (int i : path)
  //   cout << i << ' ';
  // cout << endl;
  return path;
}

int cnt[300005];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    _elist1[u].pb(v);
    _elist1[v].pb(u);
  }
  vis[1] = 1;
  getspanningtree(1);
  int q;
  cin >> q;
  map<pii, int> qids;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    qa[i] = a, qb[i] = b;
    cnt[a]++, cnt[b]++;
  }
  int c = 0;
  for (int i = 1; i <= n; i++)
    c += cnt[i] % 2;
  if (c) {
    cout << "NO" << endl;
    cout << c / 2 << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < q; i++) {
    vector<int> v = getpath(qa[i], qb[i]);
    cout << v.size() << endl;
    for (int i : v)
      cout << i << ' ';
    cout << endl;
  }
}