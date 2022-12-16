#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
const int BASIC = 0;
const int SMALLEST = 1;
const int LARGEST = 2;
const int BOTH = 3;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

ll dist[N*4];

int encode(int u, int type) {
  return u*4 + type;
}
pair<int, int> decode(int x) {
  return {x/4, x%4};
}

vector<pair<int, ll>> adj[N];

int n, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i=0; i<m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  memset(dist, INFLL, sizeof dist);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  dist[encode(1, BASIC)] = 0;
  pq.push({0, encode(1, BASIC)});
  while (!pq.empty()) {
    auto [di, idx] = pq.top(); pq.pop();
    if (dist[idx] != di) {
      continue;
    }
    auto [u, type] = decode(idx);
    for (auto& [v, co] : adj[u]) {
      for (int t=0; t<4; ++t) {
        if ((t&type) != type) {
          continue;
        }
        int jdx = encode(v, t);
        ll ndist = dist[idx] + co;
        if ((t&1) != (type&1)) {
          ndist += co;
        }
        if ((t&2) != (type&2)) {
          ndist -= co;
        }
        if (ndist < dist[jdx]) {
          dist[jdx] = ndist;
          pq.push({ndist, jdx});
        }
      }
    }
  }
  for (int i=2; i<=n; ++i) {
    cout << dist[encode(i, BOTH)] << " ";
  }
  cout << "\n";
  return 0;
}