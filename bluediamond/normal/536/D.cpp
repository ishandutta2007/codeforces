#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
const int N = 2000 + 7;
const ll INF = (ll) 1e18;
int n, m, s, t;
ll v[N];
ll dist_s[N];
ll dist_t[N];

struct Edge {
  int to;
  ll cost;
};

vector<Edge> g[N];

void build(int root, ll dist[]) {
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  dist[root] = 0;
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto &it : g[a]) {
      int b = it.to;
      ll cost = it.cost + dist[a];
      if (cost < dist[b]) {
        dist[b] = cost;
        q.push(b);
      }
    }
  }
}

struct Point {
  int x;
  int y;
  ll v;
};

Point p[N];
pair<int, ll> memo[N][N];
ll dp[2][N][N];
ll kwk1[N][N];
ll kwk2[N][N];
int nxt1[N][N];
int nxt2[N][N];

pair<int, ll> operator + (pair<int, ll> a, pair<int, ll> b) {
  return {a.first + b.first, a.second + b.second};
}

pair<int, ll> operator - (pair<int, ll> a, pair<int, ll> b) {
  return {a.first - b.first, a.second - b.second};
}

pair<int, ll> get(int r1, int c1, int r2, int c2) {
  return memo[r2][c2] - memo[r1 - 1][c2] - memo[r2][c1 - 1] + memo[r1 - 1][c1 - 1];
}

pair<int, ll> get(int r1, int c1) {
  return get(r1, c1, n, m);
}

int get_cnt(int r1, int c1) {
  return get(r1, c1).first;
}

ll sum(int r1, int c1) {
  return get(r1, c1).second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  for (int i = 1; i <= n; i++) { /// just for fun
    shuffle(g[i].begin(), g[i].end(), rng);
  }
  build(s, dist_s);
  build(t, dist_t);
  map<ll, int> tx, ty;
  for (int i = 1; i <= n; i++) {
    tx[dist_s[i]] = 0;
    ty[dist_t[i]] = 0;
  }
  int cnt = n;
  n = m = 0;
  for (auto &it : tx) {
    it.second = ++n;
  }
  for (auto &it : ty) {
    it.second = ++m;
  }
  for (int i = 1; i <= cnt; i++) {
    p[i] = {tx[dist_s[i]], ty[dist_t[i]], v[i]};
    memo[p[i].x][p[i].y].first++;
    memo[p[i].x][p[i].y].second += v[i];
  }
  n++;
  m++;
  for (int i = 1; i <= n; i++) {
    pair<int, ll> pref = {0, 0};
    for (int j = 1; j <= m; j++) {
      pref = pref + memo[i][j];
      memo[i][j] = pref + memo[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (get_cnt(i, j) == 0) {
        continue;
      }
      nxt1[i][j] = nxt2[i][j] = N - 2;
      int lo = i + 1, hi = n;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (get_cnt(mid, j) < get_cnt(i, j)) {
          nxt1[i][j] = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      lo = j + 1;
      hi = m;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (get_cnt(i, mid) < get_cnt(i, j)) {
          nxt2[i][j] = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      kwk1[i][j] = -INF;
      kwk2[i][j] = +INF;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      int cur = get(i, j).first;
      if (cur == 0) {
        dp[0][i][j] = dp[1][i][j] = 0;
      } else {
        dp[0][i][j] = -INF;
        dp[0][i][j] = kwk1[nxt1[i][j]][j];
        dp[0][i][j] += sum(i, j);
        dp[1][i][j] = +INF;
        dp[1][i][j] = kwk2[i][nxt2[i][j]];
        dp[1][i][j] -= sum(i, j);
      }
      kwk1[i][j] = max(kwk1[i + 1][j], dp[1][i][j] - sum(i, j));
      kwk2[i][j] = min(kwk2[i][j + 1], dp[0][i][j] + sum(i, j));
    }
  }
  if (dp[0][1][1] == 0) {
    cout << "Flowers\n";
    return 0;
  }
  if (dp[0][1][1] < 0) {
    cout << "Cry\n";
  } else {
    cout << "Break a heart\n";
  }
  return 0;
}