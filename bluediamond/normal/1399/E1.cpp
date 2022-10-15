#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct E {
  int weight;
  int cnt;
};

bool operator < (E a, E b) {
  ll da = (ll) a.weight * a.cnt - (ll) a.weight / 2 * a.cnt;
  ll db = (ll) b.weight * b.cnt - (ll) b.weight / 2 * b.cnt;
  return da < db;
}

const int N = (int) 1e5 + 7;
int n, cnt[N];
ll s, c;
vector<pair<int, int>> g[N];
priority_queue<E> pq;

void dfs(int a, int p) {
  bool leaf = ((int) g[a].size() - (p != -1)) == 0;
  if (leaf) {
    cnt[a] = 1;
    return;
  }
  for (auto &it : g[a]) {
    int b = it.first;
    if (b != p) {
      dfs(b, a);
      c += (ll) it.second * cnt[b];
      pq.push({it.second, cnt[b]});
      cnt[a] += cnt[b];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n >> s;
    c = 0;
    while (!pq.empty()) {
      pq.pop();
    }
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0;
      g[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      g[x].push_back({y, w});
      g[y].push_back({x, w});
    }
    dfs(1, -1);
    int sol = 0;
    while (c > s) {
      sol++;
      auto it = pq.top();
      pq.pop();
      c -= (ll) it.weight * it.cnt;
      it.weight /= 2;
      if (it.weight > 0) {
        c += (ll) it.weight * it.cnt;
        pq.push(it);
      }
    }
    cout << sol << "\n";
  }
  return 0;
}