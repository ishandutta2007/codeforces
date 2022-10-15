#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 300 + 7;
int n;
int m;
int lim;
int a[N];
int b[N];
bool vis[N];
bool vis2[N];
vector<int> nodes;
vector<int> g[N];

void dfs(int a) {
  vis[a] = 1;
  for (auto &b : g[a]) if (vis[b] == 0) {
    dfs(b);
  }
  nodes.push_back(a);
}

struct T {
  int x;
  int y;
  int w;
};

vector<T> sol;

void add(int x, int y, int w) {
  if (w == 0) return;
  a[x] -= w;
  a[y] += w;
  sol.push_back({x, y, w});
  assert(0 <= a[x] && a[x] <= lim);
  assert(0 <= a[y] && a[y] <= lim);
}

void print() {
  cout << (int) sol.size() << "\n";
  for (auto &it : sol) {
    cout << it.x << " " << it.y << " " << it.w << "\n";
  }
}

bool found;
vector<int> path;
vector<int> cur;

void fpath(int x, int y) {
  if (found) return;
  cur.push_back(x);
  if (x == y) {
    found = 1;
    path = cur;
    cur.pop_back();
    return;
  }
  vis2[x] = 1;
  for (auto &k : g[x]) {
    if (vis2[k] == 0) {
      fpath(k, y);
    }
  }
  cur.pop_back();
}

void send(int pos, int d) {
  if (pos == 0) return;
  int x = path[pos];
  int x2 = path[pos - 1];
  int t = min(d, a[x2]);
  add(x2, x, t);
  send(pos - 1, d);
  add(x2, x, d - t);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> lim >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int xn = 1; xn <= n; xn++) {
    if (vis[xn] == 0) {
      nodes.clear();
      dfs(xn);
      int dif = 0;
      for (auto &x : nodes) dif += a[x] - b[x];
      if (dif != 0) {
        cout << "NO\n";
        return 0;
      }
      while (1) {
        int s = -1, t = -1;
        for (auto &x : nodes) {
          if (a[x] > b[x]) {
            s = x;
          }
          if (a[x] < b[x]) {
            t = x;
          }
        }
        if (s == -1) {
          break;
        }
        assert(t != -1);
        for (auto &x : nodes) vis2[x] = 0;
        found = 0;
        cur.clear();
        path.clear();
        fpath(s, t);
        assert(found);
        send((int) path.size() - 1, min(a[s] - b[s], b[t] - a[t]));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    assert(a[i] == b[i]);
  }
  print();
}