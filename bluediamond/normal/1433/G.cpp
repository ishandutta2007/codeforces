#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 7;
const int INF = (int) 1e9;
int n;
int m;
int k;
int x[N];
int y[N];
int w[N];
int f[N];
int s[N];
int d[N][N];
vector<int> g[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> w[i];
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = INF;
    }
  }
  for (int i = 1; i <= n; i++) {
    priority_queue<pair<int, int>> q;
    q.push({0, i});
    for (int j = 1; j <= n; j++) {
      if (d[i][j] != INF) {
        q.push({-d[i][j], j});
      }
    }
    d[i][i] = 0;
    while (!q.empty()) {
      int v = -q.top().first;
      int a = q.top().second;
      q.pop();
      if (v != d[i][a]) continue;
      for (auto &id : g[a]) {
        int b = x[id] + y[id] - a;
        if (v + w[id] < d[i][b]) {
          d[i][b] = d[b][i] = v + w[id];
          q.push({-d[i][b], b});
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    cin >> f[i] >> s[i];
  }
  int sol = INF;
  for (int i = 1; i <= m; i++) {
    int v = 0;
    for (int j = 1; j <= k; j++) {
      int dist = min(d[f[j]][s[j]], min(d[f[j]][x[i]] + d[s[j]][y[i]], d[f[j]][y[i]] + d[s[j]][x[i]]));
      v += dist;
    }
    sol = min(sol, v);
  }
  cout << sol << "\n";
}