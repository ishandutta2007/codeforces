#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 423456
const int P = 998244353;
const int T = 20;

int n, m;
vector<array<int, 2>> adj[maxN];
array<int, 2> dis[maxN];
set<array<int, 3>> hp;
int Dis[maxN][22];
int main() {
  scanf("%d%d", &n, &m);
  n *= 2;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[2 * u - 1].push_back({2 * v - 1, 0});
    adj[2 * v - 1].push_back({2 * u, 1});
    adj[2 * v].push_back({2 * u, 0});
    adj[2 * u].push_back({2 * v - 1, 1});
  }
  dis[1] = {0, 0};
  for (int i = 2; i <= n; i++)
    dis[i] = {1 << 30, 1 << 30};
  for (int i = 1; i <= n; i++)
    hp.insert({dis[i][0], dis[i][1], i});
  for (int i = 0; i < n; i++) {
    auto v = (*hp.begin())[2];
    hp.erase(hp.begin());
    for (auto edge : adj[v]) {
      int u = edge[0];
      array<int, 2> ndis{dis[v][0] + edge[1], dis[v][1] + 1};
      if (ndis < dis[u]) {
        hp.erase({dis[u][0], dis[u][1], u});
        dis[u] = ndis;
        hp.insert({dis[u][0], dis[u][1], u});
      }
    }
  }
  auto d = min(dis[n], dis[n - 1]);
  if (d[0] >= T) {
    i64 answer = 1;
    for (int i = 0; i < d[0]; i++)
      answer = answer * 2 % P;
    answer = (answer + d[1] + P - 1) % P;
    printf("%lld\n", answer);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < T; j++)
      Dis[i][j] = 1 << 30;
  Dis[1][0] = 0;
  queue<array<int, 2>> q;
  q.push({1, 0});
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int d = Dis[p[0]][p[1]];
    for (auto edge : adj[p[0]]) {
      int v = edge[0], lev = p[1] + edge[1];
      if (lev >= T)
        continue;
      if (Dis[v][lev] == 1 << 30) {
        Dis[v][lev] = d + 1;
        q.push({v, lev});
      }
    }
  }
  int answer = (1 << d[0]) + d[1];
  for (int i = 0; i < T; i++) {
    answer = min(answer, Dis[n][i] + (1 << i) - 1);
    answer = min(answer, Dis[n - 1][i] + (1 << i) - 1);
  }
  printf("%d\n", answer);
}