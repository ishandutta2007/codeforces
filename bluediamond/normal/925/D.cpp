#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
int n;
int m;
vector<int> g[N];
int dist[N];
int par[N];
int c[N];
int cnt[N];
int cc;
int many;
bool good[N];

void print(vector<int> ret) {
  cout << (int) ret.size() - 1 << "\n";
  for (auto &x : ret) {
    cout << x << " ";
  }
  cout << "\n";
  exit(0);
}

void dfs(int x) {
  many++;
  c[x] = cc;
  for (auto &y : g[x]) {
    cnt[cc] += (x < y);
    if (c[y] == 0) {
      dfs(y);
    }
  }
}

ll f(ll n) {
  return n * (n - 1) / 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  int nope = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    nope += (x != n && y != n);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = -1;
  }
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto &b : g[a]) {
      if (dist[b] == -1) {
        dist[b] = 1 + dist[a];
        par[b] = a;
        q.push(b);
      }
    }
  }
  if (dist[n] != -1 && dist[n] < 4) {
    vector<int> c;
    int node = n;
    while (node) {
      c.push_back(node);
      node = par[node];
    }
    reverse(c.begin(), c.end());
    print(c);
  }
  for (int i = 1; i <= n; i++) {
    for (auto &j : g[i]) {
      if (dist[i] == 1 && dist[j] == 2) {
        print({1, i, j, 1, n});
      }
    }
  }
  g[1].clear();
  for (int i = 2; i <= n; i++) {
    sort(g[i].rbegin(), g[i].rend());
    if (!g[i].empty() && g[i].back() == 1) {
      g[i].pop_back();
    }
    reverse(g[i].begin(), g[i].end());
  }
  for (int i = 1; i <= n; i++) {
    if (c[i] == 0 && dist[i] == 1) {
      cc++;
      many = 0;
      dfs(i);
      if (cnt[cc] == f(many)) {
        continue;
      }
      for (int a = 1; a <= n; a++) {
        if (c[a] == cc && (int) g[a].size() < many) {
          for (int i = 1; i <= n; i++) {
            good[i] = 1;
          }
          good[a] = 0;
          for (auto &b : g[a]) {
            good[b] = 0;
          }
          for (auto &b : g[a]) {
            for (auto &c : g[b]) {
              if (good[c]) {
                print({1, a, b, c, a, n});
              }
            }
          }
        }
      }
    }
  }
  cout << "-1\n";
}