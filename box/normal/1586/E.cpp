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
set<int> elist2[300005];
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

vector<int> cet;

int _gn(int id, int u) { return qa[id] ^ qb[id] ^ u; }

void ersed(int id) {
  elist2[qa[id]].erase(id);
  elist2[qb[id]].erase(id);
}

void dfseuler(int u) {
  int cur = -1;
  while (elist2[u].size()) {
    cur = *elist2[u].lower_bound(cur);
    ersed(cur);
    dfseuler(_gn(cur, u));
  }
  cet.push_back(u);
}

vector<int> ans[300005];

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
    if (qids.count({a, b})) {
      int f = qids[{a, b}];
      qids.erase({a, b});
      qids.erase({b, a});
      elist2[a].erase(f);
      elist2[b].erase(f);
      ans[i] = ans[f] = getpath(a, b);
    } else {
      qids[{a, b}] = qids[{b, a}] = i;
      elist2[a].insert(i);
      elist2[b].insert(i);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    cnt += elist2[i].size() % 2;
  if (cnt) {
    cout << "NO" << endl;
    cout << cnt / 2 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (elist2[i].size()) {
      cet.clear();
      dfseuler(i);
      // for (int i : cet)
      //   cout << i << " ";
      // cout << endl;
      int sz = cet.size();
      int pv = -1;
      vector<pii> eds;
      for (int x = 0; x < sz - 2; x++) {
        auto ss = getpath(cet[x], cet[x + 1]);
        ans[qids[{cet[x], cet[x + 1]}]] = ss;
        for (int el = 0; el < ss.size() - 1; el++) {
          pii cur = {ss[el], ss[el + 1]};
          if (eds.size() && eds.back().fi == cur.se)
            eds.pop_back();
          else
            eds.pb(cur);
        }
      }
      vector<int> att;
      att.pb(eds[0].fi);
      for (auto [U, V] : eds)
        att.pb(V);
      ans[qids[{cet[sz - 2], cet[sz - 1]}]] = att;
    }
  cout << "YES" << endl;
  for (int i = 0; i < q; i++) {
    if (ans[i].front() != qa[i])
      reverse(all(ans[i]));
    cout << ans[i].size() << endl;
    for (int j : ans[i])
      cout << j << ' ';
    cout << endl;
  }
}