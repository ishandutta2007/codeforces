#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int K = 23;
const int N = 200000 + 7;
const int M = 998244353;
const int INF = (int) 1e9;

struct T {
  int i;
  int j;
};

T min(T a, T b) {
  if (a.i < b.i) {
    return a;
  }
  if (b.i < a.i) {
    return b;
  }
  if (a.j < b.j) {
    return a;
  } else {
    return b;
  }
}

bool operator < (T a, T b) {
  if (a.i != b.i) {
    return a.i < b.i;
  } else {
    return a.j < b.j;
  }
}

T really_best(T a, T b) {
  if (a.i >= INF || a.j >= INF) {
    return b;
  }
  if (b.i >= INF || b.j >= INF) {
    return a;
  }
  if (a.i == b.i) {
    if (a.j < b.j) {
      return a;
    } else {
      return b;
    }
  }
  if (a.i >= K || b.i >= K) {
    if (a.i < b.i) {
      return a;
    } else {
      return b;
    }
  }
  ll va = (1LL << a.i) - 1 + a.j;
  ll vb = (1LL << b.i) - 1 + b.j;
  if (va < vb) {
    return a;
  } else {
    return b;
  }
}

struct P {
  int k;
  int i;
};

struct P2 {
  int k;
  int i;
  int cnt;
};

int n;
int m;
vector<int> g[2][N];
T dist_n[2][N];
int dist_1[2][N][K];

bool operator < (P2 a, P2 b) {
  return !(dist_1[a.k][a.i][a.cnt] < dist_1[b.k][b.i][b.cnt]);
}

bool operator < (P a, P b) {
  return !(dist_n[a.k][a.i] < dist_n[b.k][b.i]);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[0][x].push_back(y);
    g[1][y].push_back(x);
  }
  for (int i = 1; i < n; i++) {
    dist_n[0][i] = dist_n[1][i] = {INF, INF};
  }
  priority_queue<P> pq;
  pq.push({0, n});
  pq.push({1, n});
  while (!pq.empty()) {
    int k = pq.top().k;
    int i = pq.top().i;
    pq.pop();
    for (auto &j : g[k ^ 1][i]) {
      T potential = {dist_n[k][i].i , dist_n[k][i].j + 1};
      if (potential < dist_n[k][j]) {
        dist_n[k][j] = potential;
        pq.push({k, j});
      }
    }
    T potential = {dist_n[k][i].i + 1, dist_n[k][i].j};
    if (potential < dist_n[k ^ 1][i]) {
      dist_n[k ^ 1][i] = potential;
      pq.push({k ^ 1, i});
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < K; k++) {
      dist_1[0][i][k] = dist_1[1][i][k] = INF;
    }
  }
  priority_queue<P2> q;
  dist_1[0][1][0] = 0;
  q.push({0, 1, 0});
  while (!q.empty()) {
    int k = q.top().k;
    int i = q.top().i;
    int c = q.top().cnt;
    q.pop();
    for (auto &j : g[k][i]) {
      int potential = dist_1[k][i][c] + 1;
      if (potential < dist_1[k][j][c]) {
        dist_1[k][j][c] = potential;
        q.push({k, j, c});
      }
    }
    if (c + 1 < K) {
      int potential = dist_1[k][i][c];
      if (potential < dist_1[k ^ 1][i][c + 1]) {
        dist_1[k ^ 1][i][c + 1] = potential;
        q.push({k ^ 1, i, c + 1});
      }
    }
  }
  T best = {INF, INF};
  for (int k = 0; k <= 1; k++) {
    for (int i = 1; i <= n; i++) {
      for (int c = 0; c < K; c++) {
        T first = {c, dist_1[k][i][c]};
        T second = dist_n[k][i];
        T sum = {first.i + second.i, first.j + second.j};
        best = really_best(best, sum);
      }
    }
  }
  int sol = 1;
  for (int i = 1; i <= best.i; i++) {
    sol = (2 * sol) % M;
  }
  sol = (sol + M - 1) % M;
  sol = (sol + best.j) % M;
  cout << sol << "\n";
}