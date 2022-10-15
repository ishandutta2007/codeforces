#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 600 + 7;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

int n, m, dist[N][N], x[N], y[N], ret[N][N], yolo[N][N];
bool use[N][N];
vector<int> g[N];

int other(int i, int a) {
  return x[i] + y[i] - a;
}

void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ret[i][j] << " ";
    }
    cout << "\n";
  }
  exit(0);
}

int get(int a, int b) {
  int ret = 1;
  int lol = 0;
  for (int node = 1; node <= n; node++) {
    if (dist[a][node] + dist[node][b] == dist[a][b]) {
      lol++;
      continue;
    }
    int cnt = 0;
    for (auto &ind : g[node]) {
      int vec = other(ind, node);
      int dif1 = dist[a][node] - dist[a][vec];
      int dif2 = dist[b][node] - dist[b][vec];
      cnt += (dif1 == 1 && dif2 == 1);
    }
    ret = mul(ret, cnt);
  }
  if (lol != 1 + dist[a][b]) {
    return 0;
  }
  return ret;
}

vector<vector<int>> lol[N];
int val[N], t[N];

int root(int x) {
  if (t[x] == x) return x;
  return t[x] = root(t[x]);
}

void unite(int x, int y) {
  t[root(x)] = root(y);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen ("input", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i];
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dist[i][j] = -1;
    dist[i][i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (auto &ind : g[a]) {
        int b = other(ind, a);
        if (dist[i][b] == -1) {
          dist[i][b] = 1 + dist[i][a];
          q.push(b);
        }
      }
    }
    for (int j = 1; j <= m; j++) {
      if (abs(dist[i][x[j]] - dist[i][y[j]]) == 1) {
        use[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int node = 1; node <= n; node++) {
      vector<int> now;
      for (auto &ind : g[node]) {
        int vec = other(ind, node);
        if (dist[i][vec] == dist[i][node] - 1) {
          now.push_back(ind);
        }
      }
      sort(now.begin(), now.end());
      if (!now.empty()) {
        lol[i].push_back(now);
        for (auto &x : now) {
          yolo[i][x] = (int) lol[i].size();
        }
      }
    }
    sort(lol[i].begin(), lol[i].end());
    val[i] = 1;
    for (auto &v : lol[i]) {
      val[i] = mul(val[i], (int) v.size());
    }
  }
  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      ret[a][b] = get(a, b);
    }
  }
  print();
}