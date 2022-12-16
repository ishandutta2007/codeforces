#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
const int INF = 0x3f3f3f3f;
vector<int> adj[N];
int dist[N];
int ans[N];

int sz[N];
bool taken[N];

void sdfs(int u, int p) {
  sz[u] = 1;
  for (auto& v : adj[u]) {
    if (v == p) continue;
    if (taken[v]) continue;
    sdfs(v, u);
    sz[u] += sz[v];
  }
}

int rdfs(int u, int p, int n) {
  pair<int, int> pr = {0, 0};
  for (auto& v : adj[u]) {
    if (v == p) continue;
    if (taken[v]) continue;
    pr = max(pr, {sz[v], v});
  }
  if (pr.first*2 < n) {
    return u;
  }
  return rdfs(pr.second, u, n);
}

void mdfs(int u, int p, int d, vector<tuple<int, int, int>>& members) {
  members.push_back({u, d, dist[u]});
  for (auto& v : adj[u]) {
    if (v == p) continue;
    if (taken[v]) continue;
    mdfs(v, u, d+1, members);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dist, INF, sizeof dist);
  int k;
  cin >> k;
  queue<int> q;
  for (int i=0; i<k; ++i) {
    int u;
    cin >> u;
    dist[u] = 0;
    q.push(u);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto& v : adj[u]) {
      if (dist[v] == INF) {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }
  queue<int> qu;
  qu.push(1);
  vector<tuple<int,int,int>> members;
  vector<int> amts(n+1);
  while (!qu.empty()) {
    int base = qu.front(); qu.pop();
    sdfs(base, 0);
    int r = rdfs(base, 0, sz[base]);
    taken[r] = 1;
    for (int i=0; i<=sz[base]; ++i) {
      amts[i] = 0;
    }
    members.clear();
    mdfs(r, 0, 0, members);
    for (auto& [u, d, du] : members) {
      amts[d] = max(amts[d], du);
    }
    for (int i=1; i<=sz[base]; ++i) {
      amts[i] = max(amts[i-1], amts[i]);
    }
    for (auto& [u, d, _] : members) {
      int lo = 0, hi = sz[base];
      while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (amts[mid] > d+mid) {
          lo = mid;
        } else {
          hi = mid-1;
        }
      }
      if (amts[lo] > d+lo) {
        ans[u] = max(ans[u], amts[lo]);
      }
    }
    for (auto& v : adj[r]) {
      if (!taken[v]) {
        qu.push(v);
      }
    }
  }
  for (int i=1; i<=n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}