#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
int uf[N];
void setup() {
  memset(uf, -1, sizeof uf);
}
int FIND(int u) {
  if (uf[u] == -1) return u;
  return uf[u] = FIND(uf[u]);
}
bool UNION(int u, int v) {
  if (FIND(u) == FIND(v)) {
    return false;
  }
  uf[FIND(u)] = FIND(v);
  return true;
}

int n, m;
set<int> adj[N];
bool seen[N];
set<int> s;
int ans;

void dfs(int u) {
  if (seen[u]) {
    return;
  }
  seen[u] = 1;
  vector<int> nbrs;
  s.erase(u);
  for (auto it=s.begin(); it!=s.end();) {
    int v = *it++;
    if (!adj[u].count(v)) {
      s.erase(prev(it));
      nbrs.push_back(v);
      if (UNION(u, v)) {
        --ans;
      }
    }
  }
  for (auto& v : nbrs) {
    dfs(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  setup();
  for (int i=1; i<=m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  ans = n;
  for (int i=1; i<=n; ++i) {
    s.insert(i);
  }
  for (int u=1; u<=n; ++u) {
    dfs(u);
  }
  vector<int> amt(n+1);
  vector<int> sizes;
  for (int i=1; i<=n; ++i) {
    amt[FIND(i)] ++;
  }
  for (int i=1; i<=n; ++i) {
    if (amt[i]) {
      sizes.push_back(amt[i]);
    }
  }
  sort(sizes.begin(), sizes.end());
  cout << ans << "\n";
  for (auto& x : sizes) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}