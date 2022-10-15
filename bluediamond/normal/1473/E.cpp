#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct E {
  int x;
  int w;
};

const int N = (int) 2e5 + 7;
const ll INF = (ll) 1e18;
int n;
int m;
vector<E> g[N];
ll dp[N][4];

struct T {
  ll x;
  int i;
  int j;
};

bool operator < (T a, T b) {
  return a.x > b.x;
}

priority_queue<T> pq;

void upd(ll x, int i, int j) {
  if (x < dp[i][j]) {
    dp[i][j] = x;
    pq.push({x, i, j});
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      dp[i][j] = INF;
    }
  }
  upd(0, 1, 0);
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    if (dp[it.i][it.j] != it.x) {
      continue;
    }
    int i = it.i;
    int j = it.j;
    for (auto &edg : g[i]) {
      int node = edg.x;
      ll value = edg.w + dp[i][j];
      if (j == 0) {
        upd(value, node, 0);
        upd(value - edg.w, node, 1);
        upd(value + edg.w, node, 2);
        upd(value - edg.w + edg.w, node, 3);
      }
      if (j == 1) {
        upd(value, node, 1);
        upd(value + edg.w, node, 3);
      }
      if (j == 2) {
        upd(value, node, 2);
        upd(value - edg.w, node, 3);
      }
      if (j == 3) {
        upd(value, node, 3);
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << dp[i][3] << " ";
  }
  cout << "\n";
}