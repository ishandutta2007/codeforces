#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 606;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
ll adj[N][N];
int taken[N];
ll dist[N];
int n;

void upd(ll& x, ll y) {
  x = min(x, y);
}

void dijkstra(int start) {
  memset(dist, INFLL, sizeof dist);
  memset(taken, 0, sizeof taken);
  for (int i=0; i<n; ++i) {
    upd(dist[i], adj[start][i]);
  }
  for (int __t=0; __t<n; ++__t) {
    int u = -1;
    for (int i=0; i<n; ++i) {
      if (taken[i]) {
        continue;
      }
      if (u == -1 || dist[i] < dist[u]) {
        u = i;
      }
    }
    taken[u] = 1;
    assert(u != -1);
    upd(dist[(u+1)%n], dist[u]+1);
    int q = dist[u]%n;
    for (int i=0; i<n; ++i) {
      upd(dist[q], dist[u] + adj[u][i]);
      ++q;
      if (q == n) {
        q = 0;
      }
    }
  }
  dist[start] = 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int m;
  cin >> n >> m;
  memset(adj, INFLL, sizeof adj);
  for (int i=0; i<m; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    adj[u][v] = x;
  }
  for (int i=0; i<n; ++i) {
    dijkstra(i);
    for (int j=0; j<n; ++j) {
      cout << dist[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}