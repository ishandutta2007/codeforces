/// 483 -> 484
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  int mn;
  int mx;
};

T operator + (T a, T b) {
  return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

const int N = (int) 3e5 + 7;
const int K = 20;
int n, a[N], dist[N], last_is_min[N], last_is_max[N], first_is_min[N], first_is_max[N];
vector<int> g[N];
T rmq[K][N];
int urm_big[K][N];
int urm_small[K][N];
int lg2[N];

void addEdge(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}

T get(int l, int r) {
  assert(1 <= l);
  assert(l <= r);
  assert(r <= n);
  int k = lg2[r - l + 1];
  return rmq[k][l] + rmq[k][r - (1 << k) + 1];
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  for (int i = 2; i < N; i++) {
    lg2[i] = 1 + lg2[i / 2];
  }

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    for (int k = 0; k < K; k++) {
      for (int i = 0; i <= n + 1; i++) {
        urm_big[k][i] = urm_small[k][i] = n + 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      rmq[0][i] = {a[i], a[i]};
      g[i].clear();
    }
    for (int k = 1; (1 << k) <= n; k++) {
      for (int i = 1; i + (1 << k) - 1 <= n; i++) {
        rmq[k][i] = rmq[k - 1][i] + rmq[k - 1][i + (1 << (k - 1))];
      }
    }
    {
      vector<int> stk;
      for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[i] > a[stk.back()]) {
          stk.pop_back();
        }
        if (stk.empty()) {
          last_is_max[i] = n;
          urm_big[0][i] = n + 1;
        } else {
          last_is_max[i] = stk.back() - 1;
          urm_big[0][i] = stk.back();
        }
        stk.push_back(i);
      }
    }
    {
      vector<int> stk;
      for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[i] < a[stk.back()]) {
          stk.pop_back();
        }
        if (stk.empty()) {
          last_is_min[i] = n;
          urm_small[0][i] = n + 1;
        } else {
          last_is_min[i] = stk.back() - 1;
          urm_small[0][i] = stk.back();
        }
        stk.push_back(i);
      }
    }
    {
      for (int k = 1; k < K; k++) {
        for (int i = 0; i <= n + 1; i++) {
          urm_big[k][i] = urm_big[k - 1][urm_big[k - 1][i]];
          urm_small[k][i] = urm_small[k - 1][urm_small[k - 1][i]];
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      int x = -1, y = -1;
      if (i + 1 <= last_is_min[i]) {
        x = urm_big[0][i];
        for (int k = K - 1; k >= 0; k--) {
          if (urm_big[k][x] <= last_is_min[i]) {
            x = urm_big[k][x];
          }
        }
      }
      if (i + 1 <= last_is_max[i]) {
        y = urm_small[0][i];
        for (int k = K - 1; k >= 0; k--) {
          if (urm_small[k][y] <= last_is_max[i]) {
            y = urm_small[k][y];
          }
        }
      }

      if (x != -1) {
        addEdge(i, x);
      }
      if (y != -1) {
        addEdge(i, y);
      }
    }
    for (int i = 1; i <= n; i++) {
      dist[i] = -1;
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (auto &b : g[a]) {
        if (dist[b] == -1) {
          dist[b] = 1 + dist[a];
          q.push(b);
        }
      }
    }
    assert(dist[n] != -1);
    cout << dist[n] << "\n";

  }
}