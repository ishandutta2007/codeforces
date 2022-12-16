#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 300100;
set<pair<ll, ll>> ch[N];
set<pair<ll, ll>> f;
int par[N];
int upidx[N];
ll n, m, x;

vector<pair<int, int>> adj[N];
ll a[N];
int vis[N];
void dfs(int u, int p) {
  vis[u] = 1;
  par[u] = p;
  for (auto& [v, e]: adj[u]) {
    if (v == p) continue;
    if (vis[v]) continue;
    ch[u].insert({a[v], v});
    upidx[v] = e;
    dfs(v, u);
  }
}

vector<int> ans;
void merge_up(int u) {
  //cerr << "MERGE UP " << u << endl;
  assert(par[u] != 0);
  int p = par[u];
  f.erase({a[u], u});
  f.erase({a[p], p});
  ans.push_back(upidx[u]);
  if (ch[u].size() > ch[p].size()) {
    //cerr << " U.size > p.size" << endl;
    ch[p].erase({a[u], u});
    for (auto& [av, v] : ch[p]) {
      ch[u].insert({av, v});
      par[v] = u;
    }
    ch[p].clear();
    if (par[p]) {
      ch[par[p]].erase({a[p], p});
    }
    a[u] += a[p]-x;
    if (par[p]) {
      ch[par[p]].insert({a[u], u});
    }
    swap(upidx[u], upidx[p]);
    par[u] = par[p];
    f.insert({a[u], u});
  } else {
    //cerr << " U.size <= p.size p" << p << endl;
    ch[p].erase({a[u], u});
    for (auto& [av, v] : ch[u]) {
      par[v] = p;
      ch[p].insert({av, v});
      //cerr << " NEW " << v << endl;
    }
    ch[u].clear();
    if (par[p]) {
      ch[par[p]].erase({a[p], p});
    }
    a[p] += a[u]-x;
    if (par[p]) {
      ch[par[p]].insert({a[p], p});
    }
    f.insert({a[p], p});
    //cerr << " ADD " << p << " with " << a[p] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> x;
  ll asum = 0;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    asum += a[i];
    f.insert({a[i], i});
  }
  if (asum < x*(n-1)) {
    cout << "NO\n";
    return 0;
  }
  for (int i=1; i<=m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  dfs(1, 0);

  while (f.size() > 1) {
    auto [au, u] = *f.rbegin();
    //cerr << "    CHOSE " << u << endl;
    int q, v;
    if (ch[u].empty() || ch[u].rbegin()->first + au < x) {
      q = u;
    } else {
      q = ch[u].rbegin()->second;
    }
    merge_up(q);
  }
  cout << "YES\n";
  for (auto& x : ans) {
    cout << x << "\n";
  }

  return 0;
}